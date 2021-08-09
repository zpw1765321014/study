#include <time.h>
#include <sys/timerfd.h>
#include <sys/socket.h>

#include "./include/swoole.h"
#include "./include/Server.h"

static void swSignalInit(void);
static int swServer_poll_loop(swThreadParam *param);
static int swServer_poll_start(swServer *serv);
static int swServer_check_callback(swServer *serv);
static int swServer_listen(swServer *serv, swReactor *reactor);
static int swServer_poll_onClose(swReactor *reactor, swEvent *event);
static int swServer_poll_onReceive(swReactor *reactor, swEvent *event);
static int swServer_poll_onPackage(swReactor *reactor, swEvent *event);
static int swServer_timer_start(swServer *serv);




/**
  swoole server 初始化
 * initializing server config, set default
 */
void swServer_init(swServer *serv)
{  
   
	bzero(serv, sizeof(swServer));
	serv->backlog = SW_BACKLOG;
	serv->factory_mode = SW_MODE_CALL;
	serv->poll_thread_num = SW_THREAD_NUM;
	serv->daemonize = 0;

	serv->ringbuffer_size = SW_QUEUE_SIZE;

	serv->timeout_sec = SW_REACTOR_TIMEO_SEC;
	serv->timeout_usec = SW_REACTOR_TIMEO_USEC; //300ms;

	serv->timer_interval = 0;

	serv->writer_num = SW_CPU_NUM;
	serv->worker_num = SW_CPU_NUM;
	serv->max_conn = SW_MAX_FDS;
	serv->max_request = SW_MAX_REQUEST;

	serv->open_udp = 0;
	serv->open_cpu_affinity = 0;
	serv->open_tcp_nodelay = 0;

	serv->udp_max_tmp_pkg = SW_MAX_TMP_PKG;

	serv->timer_list = NULL;

	serv->onClose = NULL;
	serv->onConnect = NULL;
	serv->onStart = NULL;
	serv->onShutdown = NULL;
	serv->onReceive = NULL;
	serv->onTimer = NULL;
}

/**
  server的创建
*/
int swServer_create(swServer *serv)
{

     //创建通讯管道
     int ret;
     ret = swPipeBase_create(&serv->main_pipe,0);
     
     //初始化线程池
     //create factry object

}