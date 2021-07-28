# include <stdio.h>
# include <pthread.h>
/**
 互斥量也称为互斥锁

**/
//pthread_mutex_lock; //反复枷锁会产生死锁
pthread_mutex_t mute;
int value = 0;
void *fun(void *arg){
    //上锁，函数是阻塞的
    pthread_mutex_lock(&mute);
    printf("now is %d and old value is %d \n",*((int *)arg), value);
    ++value;
    printf("now is %d and new value is %d \n",*((int *)arg), value);
    //解锁
    pthread_mutex_unlock(&mute);
}
int main(){
 
    pthread_t threads[5];
    int thread_id[5];
    //创建锁，相当于new一个对象
    pthread_mutex_init(&mute, NULL);
    for(int i=0; i<5; ++i){
        thread_id[i] = i;
        pthread_create(&threads[i], NULL, fun, (void *)&thread_id[i]);
    }
    for(int i=0; i<5; ++i)
        int rc = pthread_join(threads[i], NULL);
    //释放互斥锁
    pthread_mutex_destroy(&mute);
    return 0;
}
