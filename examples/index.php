<?php
$dict = __DIR__ . '/../dict';
var_dump(memory_get_usage());
$jieba = new PHPJieba(
    $dict . "/jieba.dict.utf8",
    $dict . "/hmm_model.utf8",
    $dict . "/user.dict.utf8",
    $dict . "/idf.utf8",
    $dict . "/stop_words.utf8"
);
unset($jieba);
var_dump(memory_get_usage());
$jieba = new PHPJieba(
    $dict . "/jieba.dict.utf8",
    $dict . "/hmm_model.utf8",
    $dict . "/user.dict.utf8",
    $dict . "/idf.utf8",
    $dict . "/stop_words.utf8"
);
$res = $jieba->cut("我是好人", true);
var_dump($res);

var_dump(memory_get_usage());

// $jieba = new PHPJieba();
