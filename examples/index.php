<?php

$res = PHPJieba::cut('来上海中山公园吃火锅', false);
var_dump(json_encode($res, JSON_UNESCAPED_UNICODE));

$res = PHPJieba::cut('来上海中山公园吃火锅', true);
var_dump(json_encode($res, JSON_UNESCAPED_UNICODE));

$res = PHPJieba::cutAll('来上海中山公园吃火锅');
var_dump(json_encode($res, JSON_UNESCAPED_UNICODE));

$res = PHPJieba::cutForSearch('来上海中山公园吃火锅');
var_dump(json_encode($res, JSON_UNESCAPED_UNICODE));

$res = PHPJieba::cutForSearch('男默女泪');
var_dump(json_encode($res, JSON_UNESCAPED_UNICODE));

PHPjieba::insertUserWord('男默女泪');

$res = PHPJieba::cutForSearch('男默女泪');
var_dump(json_encode($res, JSON_UNESCAPED_UNICODE));

