#!/bin/bash

# 新建文件夹

touch result.txt

ps -ef

top -n1  > result.txt

# 筛选出目标进程并杀死

ps -ef | grep helloworld | grep -v grep | awk '{print $2}' | xargs -n1 kill
