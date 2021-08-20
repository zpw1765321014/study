/**

  C语言库
   动态库 
   静态库
   手动加载库

   1.进程的标识 pid

     类型pid_t
     ps axf
     ps axm
     ps ax -L
     进程号 是顺时向下使用的
     getpid();
     getppid(); //当前进程的父进程号
     init  是零号进程
   2.进程的产生
     fork()  原意是叉子   
     父子进程是有调度器和调度策略来决定的
     fflush(NULL) 刷新进程的流

   3.进程的消亡及资源释放
   4.exec函数组
   5.用户权限及组权限
   7.system()函数
   8.进程会计
   9.进程时间
   10.守护进程
   
   子进程终止，父进程尚未对子进程进行回收，在此期间，子进程为“僵尸进程”。
**/