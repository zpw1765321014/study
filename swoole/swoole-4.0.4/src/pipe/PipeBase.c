/*
  +----------------------------------------------------------------------+
  | Swoole                                                               |
  +----------------------------------------------------------------------+
  | This source file is subject to version 2.0 of the Apache license,    |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.apache.org/licenses/LICENSE-2.0.html                      |
  | If you did not receive a copy of the Apache2.0 license and are unable|
  | to obtain it through the world-wide-web, please send a note to       |
  | license@swoole.com so we can mail you a copy immediately.            |
  +----------------------------------------------------------------------+
  | Author: Tianfeng Han  <mikan.tenny@gmail.com>                        |
  +----------------------------------------------------------------------+
*/

#include "swoole.h"

static int swPipeBase_read(swPipe *p, void *data, int length);
static int swPipeBase_write(swPipe *p, void *data, int length);
static int swPipeBase_getFd(swPipe *p, int isWriteFd);
static int swPipeBase_close(swPipe *p);

typedef struct _swPipeBase
{
    int pipes[2];
} swPipeBase;  //基类管道
/**
 * @brief 
 * 命名管道和匿名管道，
 * 匿名管道专门用于具有血缘关系的进程之间，完成数据传递，
 * 命名管道可以用于任何两个进程之间。swoole 中的管道都是匿名管道。
 * @param p 
 * @param blocking 
 * @return int 
 */
int swPipeBase_create(swPipe *p, int blocking)
{
    int ret;
    swPipeBase *object = sw_malloc(sizeof(swPipeBase));
    if (object == NULL)
    {
        return -1;
    }
    p->blocking = blocking;
    //创建匿名管道
    ret = pipe(object->pipes);
    if (ret < 0)
    {
        swWarn("pipe() failed. Error: %s[%d]", strerror(errno), errno);
        sw_free(object);
        return -1;
    }
    else
    {
        //Nonblock
        swSetNonBlock(object->pipes[0]);
        swSetNonBlock(object->pipes[1]);
        p->timeout = -1;
        p->object = object;
        p->read = swPipeBase_read;   //设置对应的回调函数
        p->write = swPipeBase_write;
        p->getFd = swPipeBase_getFd;
        p->close = swPipeBase_close;
    }
    return 0;
}
// swPipeBase_read 管道的读
static int swPipeBase_read(swPipe *p, void *data, int length)
{   
    //printf("read piping data from pipe %s\n",*((char *)data));
    //printf("read piping data from pipe %s\n",*((char *)data));
    swPipeBase *object = p->object;
    if (p->blocking == 1 && p->timeout > 0)
    {    
        // 由于匿名管道被设置为非阻塞式，无法实现超时等待写入
        if (swSocket_wait(object->pipes[0], p->timeout * 1000, SW_EVENT_READ) < 0)
        {
            return SW_ERR;
        }
    }
    return read(object->pipes[0], data, length);
}
// swPipeBase_write 管道的写入 管道的写入直接调用 write 即可，非阻塞式 IO 会立刻返回结果。
static int swPipeBase_write(swPipe *p, void *data, int length)
{
    swPipeBase *this = p->object;
    return write(this->pipes[1], data, length);
}
// 本函数用于获取管道的读端或者写端。
static int swPipeBase_getFd(swPipe *p, int isWriteFd)
{
    swPipeBase *this = p->object;
    return (isWriteFd == 0) ? this->pipes[0] : this->pipes[1];
}
// swPipeBase_close 关闭管道
static int swPipeBase_close(swPipe *p)
{
    int ret1, ret2;
    swPipeBase *this = p->object;
    ret1 = close(this->pipes[0]);
    ret2 = close(this->pipes[1]);
    sw_free(this);
    return 0 - ret1 - ret2;
}
