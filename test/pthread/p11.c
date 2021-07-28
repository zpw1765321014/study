#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <error.h>
#include <pthread.h>
//创建一个全局变量
struct msg{
     
      int num;
      struct msg *next;
}
struct msg *head; //头指针

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; //定义初始化互斥量
pthread_cond_t  has_data = PTHREAD_COND_INITIALIZER; //定义初始化互斥量
//错误打印函数
void err_thread(int ret,char *str)
{
    if(ret != 0){
        
        fprintf(stder,"%s:%s",str,strerror(ret));
        pthread_exit(NULL);
    }
}
//生产者
void *produser(void *arg)
{
   
    return NULL;
}
//消费者
void *consumer(void *arg)
{
    
    return NULL;
}
//主函数
int  main()
{
     int ret;
     pthread_t pid,cid;

     ret = pthread_create(&pid,NULL,produser,NULL);//生产者
     if(ret != 0){
         
           err_thread(ret,"pthread_create error");
     }
     
     ret = pthread_create(&cid,NULL,consumer,NULL);// 消费者
     if(ret != 0){
         
           err_thread(ret,"pthread_create error");
     }
     //回收线程
     pthread_join(pid,NULL);
     pthread_join(cid,NULL);

     return 0;
}