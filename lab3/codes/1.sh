#!/bin/bash

case $1 in
    ''|*[!0-9]*) echo your first input is not an integer ;exit 1 ;
esac
case $2 in
    ''|*[!0-9]*) echo your second input is not an integer ;exit 1 ;
esac

sum=$(($1+$2))
 
echo "Sum is: $sum"

if [ $1 -gt $2 ]
then 
	echo "greater number is $1";
elif [ $2 -gt $1 ]
then
    echo "greater number is $2";
else 
	echo "numbers are even";
fi
