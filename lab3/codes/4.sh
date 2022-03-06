#!bin/bash 

echo "Enter x";
read x;

echo "Enter y";
read y;

echo "Enter file name";
read file_name;

sed -n $(($x)),$(($y))p $file_name