#!/bin/bash

if ![[ "$1" = *([0-9]) && "$2" = *([0-9]) ]]
then 
    echo "Please enter integer numbers.";
fi

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
