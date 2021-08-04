/**
    
      服务器底成原理
      while(1){
          int ready = epoll_wait();//检测io
          for(i =0;i<ready;i++){
              
               recv(buffer); //操作IO
                 parse();  //解析数据

                send();  //所有的地城服务器操作
          }
      }

*/