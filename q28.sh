#! /bin/bash

rows=$1
for((i=1; i<=rows; i++));do
	for((j=1; j<=i; j++));do
		echo -n "* "
  	done
	echo 
done
