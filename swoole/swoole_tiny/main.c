#include "./include/swoole.h"
#include "./include/Server.h"

/*****初始化回调函数 start*****/
int my_onReceive(swFactory *factory, swEventData *req);
void my_onStart(swServer *serv);
void my_onShutdown(swServer *serv);
void my_onConnect(swServer *serv, int fd, int from_id);
void my_onClose(swServer *serv, int fd, int from_id);
void my_onTimer(swServer *serv, int interval);

void init_main();
/*****初始化回调函数 start*****/
int main()
{      
       //printf("server create start.....\n");
       //服务初始化
       init_main();

       return 0;
}
//初始话并且执行对应的回调函数
void init_main()
{
      swServer serv;

	   int ret;
      //服务初始化
	   swServer_init(&serv);

       //config
	  serv.backlog = 128;
	  serv.poll_thread_num = 1;
	  serv.writer_num = 1;
	  serv.worker_num = 4;
	  serv.factory_mode = 3;
	  serv.open_cpu_affinity = 1;
	  serv.open_tcp_nodelay = 1;
	  //serv.daemonize = 1;
      /************注册对应的回调事件 start*************/
      serv.onStart = my_onStart;
	  serv.onShutdown = my_onShutdown;
	  serv.onConnect = my_onConnect;
	  serv.onReceive = my_onReceive;
	  serv.onClose = my_onClose;
	  serv.onTimer = my_onTimer;
      /************注册对应的回调事件 end*************/


      //创建server
      //create Server
	ret = swServer_create(&serv);
	if (ret < 0)
	{
		swTrace("create server fail[error=%d].\n", ret);
		exit(0);
	}
      //启动server
	ret = swServer_start(&serv);
	if (ret < 0)
	{
		swTrace("start server fail[error=%d].\n", ret);
		exit(0);
	}

}

void my_onTimer(swServer *serv, int interval)
{
	switch (interval)
	{
	case 1:
		printf("Timer[%d]\n", 1);
		break;
	case 10:
		printf("Timer[%d]\n", 10);
		break;
	default:
		break;
	}
}

int my_onReceive(swFactory *factory, swEventData *req)
{
	int ret;
	char resp_data[SW_BUFFER_SIZE];
	swSendData resp;

	resp.fd = req->fd; //fd can be not source fd.
	resp.len = req->len + 8;
	resp.from_id = req->from_id;

	swTrace("Data Len=%d\n", req->len);
	snprintf(resp_data, resp.len, "Server:%s", req->data);
	resp.data = resp_data;
	ret = factory->finish(factory, &resp);
	if (ret < 0)
	{
		swWarn("send to client fail.errno=%d\n", errno);
	}
	swTrace("finish\n");
	return SW_OK;
}
//进程启动的时候
void my_onStart(swServer *serv)
{
	printf("Server is running\n");
}

void my_onShutdown(swServer *serv)
{
	printf("Server is shutdown\n");
}

void my_onConnect(swServer *serv, int fd, int from_id)
{
	printf("Connect fd=%d|from_id=%d\n", fd, from_id);
}

void my_onClose(swServer *serv, int fd, int from_id)
{
	printf("Close fd=%d|from_id=%d\n", fd, from_id);
}
//ps aux | grep swoole |  awk '{print $2}' | xargs kill -9 杀死所有对应的进程