<?php
$serv = new swoole_server("0.0.0.0", 9501);
$serv->on('connect', function ($serv, $fd, $reactor_id){
	echo "[#".posix_getpid()."]\tClient@[$fd:$reactor_id]: Connect.\n";
});
$serv->set([

    'worker_num' => 2,

]);
//设置进程开始回调函数
$serv->on('workerStart',function ($server, $worker_id){
      
       echo "workerStart{$worker_id}\n";
});
//设置接收回调函数
$serv->on('receive', function (swoole_server $serv, $fd, $reactor_id, $data) {
	echo "[#".$serv->worker_id."]\tClient[$fd] receive data: $data\n";
    if ($serv->send($fd, "hello {$data}\n") == false)
    {
        echo "error\n";
    }

});

//$serv->on('close', function ($serv, $fd, $reactor_id) {
//	echo "[#".posix_getpid()."]\tClient@[$fd:$reactor_id]: Close.\n";
//});
echo "start tcp server is startting........".PHP_EOL;
$serv->start();

// 121.199.57.48

