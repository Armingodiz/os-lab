#!bin/bash 

function print_shape1() {
	for (( i=1; i<=5; i++ ));
	do 
		for (( j=1; j<=$i; j++ ))
        do
			echo -n $i;
		done 
		echo ' ';
	done
}

function print_shape2() {
	for (( i=1; i<=5; i++ ))
	do 
		echo -n '|';
		for (( j=2; j<=$i; j++ ))
		do 
			echo -n ' |';
		done 
		echo '_';
	done 
}

function print_shape3() {
	for (( i=1; i<=5; i++ ))
	do 
		for (( j=1; j<=$((5 - $i)); j++ ))
		do 
			echo -n ' ';
		done 
		for (( j=1; j <=$((2 * $i - 1)); j++ ))
		do 
			echo -n '*';
		done 
		echo ' ';
	done 
	for (( i=1; i<=5; i++ ))
	do 
		for (( j=1; j<=$i; j++ ))
		do 
			echo -n ' ';
		done 
		for (( j=1; j <=$((2 * (5 - $i) - 1)); j++ ))
		do 
			echo -n '*';
		done 
		echo ' ';
	done 
}


echo -n "Enter number > ";
read number;

if [ $number = '1' ]
then
	print_shape1
elif [ $number = '2' ]
then
	print_shape2
elif [ $number = '3' ]
then 
	print_shape3
else
    echo "invalid shape number";
fi