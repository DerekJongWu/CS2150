#!/bin/bash 

#Derek Wu
#djw4yv
#3/14/2018

read -p 'Dictionary: ' dict 
read -p 'Word Puzzle: ' puzzle 

RUNNING_TIME1=`./a.out "$dict" "$puzzle" | tail -1` 

RUNNING_TIME2=`./a.out "$dict" "$puzzle" | tail -1`

RUNNING_TIME3=`./a.out "$dict" "$puzzle" | tail -1`

RUNNING_TIME4=`./a.out "$dict" "$puzzle" | tail -1`

RUNNING_TIME5=`./a.out "$dict" "$puzzle" | tail -1`


sum=$((${RUNNING_TIME1%%.*}+${RUNNING_TIME2%%.*}+${RUNNING_TIME3%%.*}+${RUNNING_TIME4%%.*}+${RUNNING_TIME5%%.*})) 

echo $(( ${sum%%.*} * 1000 / 5 )) 

