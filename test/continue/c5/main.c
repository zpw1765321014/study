#include"coroutine.h"
/**
  1.协成的实现需要一个协成结构体和一个调度器
  2.协成结构体：回调函数，回调函数参数，协成的状态 上下文 栈
  3.协成调度器结构体：指向协成数据的指针，当前运行的协成id,协成最大数，主函数的上下文信息

  我们需要用到的函数:getcontext、setcontext、makecontext、swapcontext
  int getcontext(ucontext_t *ucp)—保存当前寄存器信息到ucp中

  int setcontext(const ucontext_t *ucp)—将ucp中保存的寄存器信息恢复

  void makecontext(ucontext_t *ucp, void (*func)(), int argc)


  改造ucp上下文信息，下一步执行func，func执行完毕之后执行 link之后的函数

  int swapcontext(ucontext_t *oucp, ucontext_t *ucp)
  将oucp寄存器信息保存起来，将ucp的寄存器信息加载到CPU中

*/
//获取监听描述符
int tcp_init()
{
    printf("tcp_init()\n");
    //创建套接字
    int lfd = socket(AF_INET,SOCK_STREAM,0);
    if(lfd == -1){
          
           perror("socket");
           exit(1);
    }
    //设置套接字复用
    int op = 1;
     setsockopt(lfd,SOL_SOCKET,SO_REUSEADDR,&op,sizeof(op));

     //绑定地址信息
     struct sockaddr_in addr;
     addr.sin_family = AF_INET;
     addr.sin_port   = htons(9999);
     addr.sin_addr.s_addr = htonl(INADDR_ANY);
     //bind  绑定lfd
     int fd = bind(lfd,(struct sockaddr *)&addr,sizeof(addr));
     if(fd == -1){
        
         perror("bind");
         exit(-1);
     }
     //开始监听
     listen(lfd,SOMAXCONN);
     printf("tcp_init-> lfd = %d\n",lfd);
     return lfd;
}
//设置成非阻塞
void set_nonblock(int fd)
{
     //获取描述符的访问模式和文件状态
    int flgs = fcntl(fd, F_GETFL, 0);
    //设置为非阻塞
    flgs |= O_NONBLOCK;
    fcntl(fd,F_SETFL, flgs);
}
//获取新的连接
void accept_conn(int lfd,schedule_t* s, int co_ids[], void*(*call_back)(schedule_t* s, void *argc))
{
    while(1)
    {  
           
           sleep(3);
           int cfd = accept(lfd,NULL,NULL);
           
    }
}
//主函数
int main()
{

}