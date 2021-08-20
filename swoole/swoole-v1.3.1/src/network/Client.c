#include "swoole.h"
#include "Client.h"

int swClient_create(swClient *cli, int type)
{
	int _domain;
	int _type;

	switch (type)
	{
	case SW_CLIENT_TCP:
		_domain = AF_INET;
		_type = SOCK_STREAM;
		break;
	case SW_CLIENT_TCP6:
		_domain = AF_INET6;
		_type = SOCK_STREAM;
		break;
	case SW_CLIENT_UDP:
		_domain = AF_INET;
		_type = SOCK_DGRAM;
		break;
	case SW_CLIENT_UDP6:
		_domain = AF_INET6;
		_type = SOCK_DGRAM;
		break;
	default:
		return SW_ERR;
	}
	cli->sock = socket(_domain, _type, 0);
	if(cli->sock <0)
	{
		return SW_ERR;
	}
	return cli->sock;
}

int swClient_connect(swClient *cli, char *host, int port, float timeout)
{
	return 0;
}

int swClient_send(swClient *cli, char *data, int len)
{
	return 0;
}

int swClient_recv(swClient *cli, char *data, int len)
{
	return 0;
}

] fail\n");
		return SW_ERR;
	}
	this->writer_num = writer_num;
	this->writer_pti = 0;

	factory->running = 1;
	factory->object = this;
	factory->dispatch = swFactoryThread_dispatch;
	factory->finish = swFactory_finish;
	factory->start = swFactoryThread_start;
	factory->shutdown = swFactoryThread_shutdown;

	factory->onTask = NULL;
	factory->onFinish = NULL;
	return SW_OK;
}

int swFactoryThread_start(swFactory *factory)
{
	swFactoryThread *this = factory->object;
	swThreadParam *param;
	int i;
	int ret;
	pthread_t pidt;

	ret = swFactory_check_callback(factory);
	if (ret < 0)
	{
		return SW_ERR;
	}
	for (i = 0; i < this->writer_num; i++)
	{
		ret = swPipeEventfd_create(&this->writers[i].evfd, 1);
		if (ret < 0)
		{
			swTrace("create eventfd fail\n");
			return SW_ERR;
		}
		param = sw_malloc(sizeof(swThreadParam));
		if (param == NULL)
		{
			return SW_ERR;
		}
		param->object = factory;
		param->pti = i;
		if (pthread_create(&pidt, NULL, (void * (*)(void *)) swFactoryThread_writer_loop, (void *) param) < 0)
		{
			swTrace("pthread_create fail\n");
			return SW_ERR;
		}
		if (swRingQueue_init(&this->queues[i], SW_QUEUE_SIZE) < 0)
		{
			swTrace("create ring queue fail\n");
			return SW_ERR;
		}
		this->writers[i].ptid = pidt;
		//SW_START_SLEEP;
	}
	return SW_OK;
}
int swFactoryThread_shutdown(swFactory *factory)
{
	swoole_running = 0;
	swFactoryThread *this = factory->object;
	free(this->writers);
	free(this);
	return SW_OK;
}
/**
 * 写线程模式
 */
int swFactoryThread_dispatch(swFactory *factory, swEventData *buf)
{
	swFactoryThread *this = factory->object;
	int pti;
	int ret;
	uint64_t flag = 1;
	int datasize = sizeof(int)*3 + buf->len;
	char *data;

	//使用pti，避免线程切换造成错误的writer_pti
	pti = this->writer_pti;
	if (this->writer_pti >= this->writer_num)
	{
		this->writer_pti = 0;
		pti = 0;
	}

	data = sw_malloc(datasize);
	if(data == NULL)
	{
		swTrace("malloc fail\n");
		return SW_ERR;
	}
	memcpy(data, buf, datasize);
	//send data ptr. use event_fd
	if (swRingQueue_push(&(this->queues[pti]), (void *) data) < 0)
	{
		swWarn("swRingQueue_push fail.Buffer is full.Writer=%d\n", pti);
		return SW_ERR;
	}
	else
	{
		ret = this->writers[pti].evfd.write(&this->writers[pti].evfd, &flag, sizeof(flag));
		if(ret < 0)
		{
			swWarn("Send queue notice fail.errno=%d\n", errno);
		}
		this->writer_pti++;
		return ret;
	}
}

static int swFactoryThread_writer_loop(swThreadParam *param)
{
	swFactory *factory = param->object;
	swServer *serv = factory->ptr;
	swFactoryThread *this = factory->object;
	int pti = param->pti;
	int ret;
	swEventData *req;
	uint64_t flag;

	//cpu affinity setting
	if (serv->open_cpu_affinity)
	{
		cpu_set_t cpu_set;
		CPU_ZERO(&cpu_set);
		CPU_SET(pti % SW_CPU_NUM, &cpu_set);
		if (0 != pthread_setaffinity_np(pthread_self(), sizeof(cpu_set), &cpu_set))
		{
			swTrace("pthread_setaffinity_np set fail\n");
		}
	}

	//main loop
	while (swoole_running > 0)
	{
		if (swRingQueue_pop(&(this->queues[pti]), (void **) &req) == 0)
		{
			factory->last_from_id = req->from_id;
			factory->onTask(factory, req);
			//swRingMempool_free(&this->queues[pti], req);
			sw_free(req);
		}
		else
		{
			ret = this->writers[pti].evfd.read(&this->writers[pti].evfd, &flag, sizeof(flag));
			if (ret < 0)
			{
				swTrace("read fail.errno=%d", errno);
			}
		}
	}
	factory->running = 0;
	//shutdown
	this->writers[pti].evfd.close(&this->writers[pti].evfd);
	sw_free(param);
	pthread_exit(SW_OK);
	return SW_OK;
}
