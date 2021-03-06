#ifndef _SW_RINGQUEUE_H_
#define _SW_RINGQUEUE_H_

#ifdef SW_USE_RINGQUEUE_TS
#include "atomic.h"
typedef struct _swRingQueue
{
	void **data;
	char *flags;
	// 0：push ready 1: push now
	// 2：pop ready; 3: pop now
	uint size;
	uint num;
	uint head;
	uint tail;

} swRingQueue;

int swRingQueue_init(swRingQueue *, int buffer_size); //初始化
#define swRingQueue_count(q) (q->num)        
int swRingQueue_push(swRingQueue *, void *);          //入队列
int swRingQueue_pop(swRingQueue *, void **);          //出队列
#else
typedef struct _swRingQueue
{
	int head; /* 头部，出队列方向*/
	int tail; /* 尾部，入队列方向*/
	int tag; /* 为空还是为满的标志位*/
	int size; /* 队列总尺寸 */
	void **data; /* 队列空间 */
} swRingQueue;

extern int swRingQueue_init(swRingQueue *, int buffer_size);
extern int swRingQueue_push(swRingQueue *, void *);
extern int swRingQueue_pop(swRingQueue *, void **);

#define swRingQueue_empty(q) ( (q->head == q->tail) && (q->tag == 0))
#define swRingQueue_full(q) ( (q->head == q->tail) && (q->tag == 1))
#endif
#endif 
