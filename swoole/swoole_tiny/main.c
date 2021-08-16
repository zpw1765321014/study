#include "./include/swoole.h"
#include "./include/Server.h"
/**
  1.连接的建立用两种 第一种是来自客户端的建立  epollin 表示此时事件 可读
                    第二种是服务器去连接其他的服务器  epollout 表示事件可写
  2.连接的断开
             客户端断开
			 服务器端的断开
  3.消息到达
       读缓存区的数据复制到用户空间中
	   read = 0 收到客户端关闭的FIN包
	   read > 0 正常的业务逻辑
	   read = -1  出现错误 （其中一个是tcp探活包）
  4.消息发送完毕

  业务逻辑与网络之间的处理 是否要分离
  
  listenfd
  acceptfd 
**/  

/*****初始化回调函数 start*****/
int my_onReceive(swFactory *factory, swEventData *req);
void my_onStart(swServer *serv);
void my_onShutdown(swServer *serv);
void my_onConnect(swServer *serv, int fd, int from_id);
void my_onClose(swServer *serv, int fd, int from_id);
void my_onTimer(swServer *serv, int interval);
void init_main(); //初始化
/**
  服务器端需要处理的数据 
    1.recv() 接受数据  
	2.parser()解析数据 
	3.send()发送数据到客户端
**/
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
	  serv.writer_num = 1;       // 工作写进程数据量
	  serv.worker_num = 4;       //工作进程的数量
	  serv.factory_mode = 3;     // tcp 服务器
	  serv.open_cpu_affinity = 1; // 设置对应的CPU的亲和力
	  serv.open_tcp_nodelay = 1;
	  //serv.daemonize = 1;
      /************注册对应的回调事件 start*************/
      serv.onStart = my_onStart;         //服务启动的时候
	  serv.onShutdown = my_onShutdown;
	  serv.onConnect = my_onConnect;     //服务器被连接的时候
	  serv.onReceive = my_onReceive;     // 服务器接收到数据的时候
	  serv.onClose = my_onClose;         //服务器关闭的时候
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
//接受到数据被触发的事件
int my_onReceive(swFactory *factory, swEventData *req)
{
	int ret;
	char resp_data[SW_BUFFER_SIZE];
	swSendData resp;

	resp.fd = req->fd; //fd can be not source fd.
	resp.len = req->len + 8;
	resp.from_id = req->from_id;

	swTrace("Data Len=%d %s\n", req->len, req->data);
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
	printf("my_onStart 被触发的连接事件------------Server is running\n");
}

void my_onShutdown(swServer *serv)
{
	printf("Server is shutdown\n");
}

void my_onConnect(swServer *serv, int fd, int from_id)
{
	printf("my_onConnect 被触发的连接事件-------------Connect fd=%d|from_id=%d\n", fd, from_id);
}

void my_onClose(swServer *serv, int fd, int from_id)
{
	printf("my_onClose 被触发的连接事件------------Close fd=%d|from_id=%d\n", fd, from_id);
}
//ps aux | grep swoole |  awk '{print $2}' | xargs kill -9 杀死所有对应的进程