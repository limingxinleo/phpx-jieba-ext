#!/usr/bin/env sh

cp -r dict /dict
DIR=$(php-config --extension-dir)
cp -r jieba/lib/jieba.so $DIR
CONFD=$(php -i | grep "Scan this dir for additional .ini files" | awk '{print $9}')
cp -r 51_jieba.ini $CONFD
