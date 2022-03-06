#!bin/bash 

case $1 in
    ''|*[!0-9]*) echo your first input is not an integer ;exit 1 ;
esac
case $3 in
    ''|*[!0-9]*) echo your second input is not an integer ;exit 1 ;
esac


case $2 in
	'+')
		echo $(($1 + $3))
		;;
	'-')
		echo $(($1 - $3)) 
		;;
	'x')
		echo $(($1 * $3))
		;;
	'/')
        if [ $3 -eq 0 ]
        then 
	        echo "you cant devide a number by zero"; exit 1
        fi
		echo $(($1 / $3))
		;;
	*) 
		echo "Unknown operator"
		;;
esac