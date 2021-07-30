<?php

$serv = new swoole_server("127.0.0.1", 9501);

//设置异步任务的工作进程数量

$serv->set([
    'worker_num'     => 8,
    'task_worker_num' =>16,
]);

$serv->on('start', function (){

      echo "start swoole server.......".PHP_EOL;
});

//监听数据接收事件

$serv->on('receive', function($serv, $fd, $from_id, $data) {

    //投递异步任务

    $task_id = $serv->task($data);//非阻塞

    echo "同步代码执行完成\n";

});

 

//处理异步任务

$serv->on('task', function ($serv, $task_id, $from_id, $data) {

    handleFun($data);

    //返回任务执行的结果
    echo "current task_id: " . $task_id.PHP_EOL;
    $serv->finish("finish");

});


//处理异步任务的结果

$serv->on('finish', function ($serv, $task_id, $data) {

    echo  "异步任务执行完成".date("Y-m-d H:i:s",time()).PHP_EOL;

});

 
//服务器启动
$serv->start();

 
//回调函数
function handleFun($data)
{

    $data = json_decode($data,true);

   foreach ($data  as $key => $value) 
   {

      echo  json_encode($value).PHP_EOL;

      $url = "http://www.baidu.com";//调用发送模板消息接口,服务端没办法直接获取微信的接口的一些数据,此处做了一些加密

      $postUrl = $url;

      $curlPost = $value;

      $ch = curl_init(); //初始化curl

      curl_setopt($ch, CURLOPT_URL, $postUrl); //抓取指定网页

      curl_setopt($ch, CURLOPT_HEADER, 0); //设置header

      curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1); //要求结果为字符串且输出到屏幕上

      curl_setopt($ch, CURLOPT_POST, 1); //post提交方式

      curl_setopt($ch, CURLOPT_POSTFIELDS, $curlPost);

      $data = curl_exec($ch); //运行curl

     curl_close($ch);

   }

 

}