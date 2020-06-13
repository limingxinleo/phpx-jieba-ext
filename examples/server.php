<?php

$http = new Swoole\Http\Server("127.0.0.1", 9501);
$http->set([
    'enable_coroutine' => true,
    'worker_num' => 1,
    'open_tcp_nodelay' => true,
    'max_coroutine' => 100000,
    'open_http2_protocol' => true,
    'max_request' => 0,
    'socket_buffer_size' => 2 * 1024 * 1024,
    'package_max_length' => 2 * 1024 * 1024,
]);
$http->on('request', function ($request, $response) {
    $res = jieba_hello("我是好人");
    $response->end(json_encode($res));
});

$http->start();
