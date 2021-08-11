#ifndef _SW_RINGMEMPOOL_H_
#define _SW_RINGMEMPOOL_H_
#define SWRINGMEM_ITEM_MAXSIZE 65525
// swoole 内存池
typedef struct _swRingMempool
{
	int size;
	int head;
	int tail;
	char tag;
	void *mem;  //空指针

} swRingMempool;
//内存次头部
typedef struct _swRingMempool_head
{
	char tag;          //标记
	uint16_t length;   //长度大小
} swRingMempool_head;
//内存池初始化
inline int swRingMempool_init(swRingMempool *pool, void *mem, int size);
//申请内存大小
void* swRingMempool_alloc(swRingMempool *pool, int size);
//内存的释放
inline void swRingMempool_free(swRingMempool *pool, void *ptr);
//内存大小的从新设置
inline void swRingMempool_resize(swRingMempool *pool, void *ptr, int size);
#endif
