#!/bin/bash 

#Derek Wu 
#djw4yv
#3/22/2018

read -p 'enter the exponent for counter.cpp: ' exp 

if [[ "$exp" == 'quit' ]]; then
exit 1
else
(( sum = 0 ))
(( i = 1 ))
while [ $i -lt 6 ]; do 
echo 'Running iteration' $i '...'
RUNTIME=`./a.out "$exp" | tail -1`
echo 'time take:' $RUNTIME
sum=$(( ${RUNTIME%%.*} + ${sum%%.*} ))
(( ++i ))
done

num=$(( ${i%%.*} - 1 ))
echo $num 'iterations took' $sum 'ms'
average=$(( ${sum%%.*} / 5 ))

echo 'Average time was' $average 'ms' 
exit 1
fi

