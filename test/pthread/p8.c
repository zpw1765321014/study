#include <stdio.h>
/*
  try 是锁尝试枷锁  
  读写锁  读共享 写优先 写的优先级高
  锁只有一把以读的方式给数据枷锁---读锁 以写的方式给数据枷锁 ---写锁
  相对于互斥锁 而言,当线程多的时候,提高访问效率
*/
/**
   pthread_rwlock_t rwlock;
   pthread_rwlock_init(&rwlock,NUll);
   pthread_rwlock_rdlock(&rwlock);
   pthread_rwlock_wrlock(&rwlock);
   pthread_rwlock_unlocl(&rwlock);
   pthread_rwlock_destroy(&rwlock);
*/
int main()
{

}