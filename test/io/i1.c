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

  4.说的可移植一定是标准IO (也就是兼容不同的平台)
    系统IO  也就是 操作系统提供出来的IO  每一个操作 系统提供出来的IO不一样
    所以 为了兼顾不同的操作 系统  开发人员需要使用标准IO

  5.input & output ,是一切实现的基础
    stdio标准IO
    sysio 系统调用IO  文件io

  6.fd 是在文件IO中贯穿始终的类型
    文件描述符的概念
    文件描述符的概念  整形数,数组的下表，文件描述符优先使用文件范围内最小的

    文件描述符数组是存放在 当前进程空间的
*/