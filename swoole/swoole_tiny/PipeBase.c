#include "./include/swoole.h"

//读函数
int swPipeBase_read(swPipe *p,void *data,int length);
//写函数
int swPipeBase_write(swPipe *p,void *data,int length);
//获取管道的fd
int swPipeBase_getFd(swPipe *p,int isWriteFd);
//关闭管道
void swPipeBase_close();

//管道结构体
typedef struct _swPipeBase
{
    int pipes[2];
} swPipeBase;

//管道的创建
int swPipeBase_create(swPipe *p,int blocking)
{
     int ret;
     swPipeBase *object = sw_malloc(sizeof(swPipeBase));
     if(object == NULL){
        
         return -1;
     }
     p->blocking = blocking;
     //创建管道
     ret = pipe(object->pipes);
     //管道创建失败
     if(ret < 0){
          
           return -1;
     }else{
           
           //Nonblocking 管道设置为非阻塞
           if(blocking == 0){
              	swSetNonBlock(object->pipes[0]);
			    swSetNonBlock(object->pipes[1]);
          }
          
          p->object = object;
          /*设置回调函数 start*/
          p->read = swPipeBase_read;
          p->write = swPipeBase_write;
          p->getFd = swPipeBase_getFd;
          p->close = swPipeBase_close;
           /*设置回调函数 end*/
     }
     return 0;
}
//管道读取数据
int swPipeBase_read(swPipe *p,void *data,int length)
{
    swPipeBase *this = p->object;
    return read(this->pipes[0],data,length);
}


