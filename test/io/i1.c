#include <stdio.h>
/**
  1.文件描述符  指向文件的指针   FILE *fp;
  标准输入输出 错误 stdin  std out stderr
  PCB进程控制块:本质是结构体
  成员  文件描述符
  文件描述符  0/1/2/3/4.....1023 表中最小的

  2.阻塞 和非阻塞  设备文件或者网络文件的属性
   读设备文件 和读网络文件会产生阻塞 
   /dev/tty-----终端文件

  3.fcntl 改变一个文件的访问属性
    int flgs = fcntl()
    获取文件属性 F_GETFL
    设置文件属性 F_SETFL
*/