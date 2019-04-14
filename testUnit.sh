#!/bin/bash
	
	filepath=$(dirname "$1")
	length=$(echo -n $1 | wc -c)
	length=$(($length-2))
	filename=$(echo $1|cut -c1-$length)
	cat "$filename.c"
	make --no-print-directory backUnit file=$filename path=$filepath||exit
	output2=$($filepath"/a.out")
	return2=$(echo $?)
	echo "\noutput comp:"$output2
	echo "return value comp:"$return2"\n"
	gcc "$filename.c" -o "$filepath/a.out"
	output1=$($filepath/a.out)
	return1=$(echo $?)
	echo "\noutput gcc:"$output1
	echo "return value gcc:"$return1"\n"
	if [ "$output1" = "$output2" ] && [ "$return1" = "$return2" ] ;then
		echo "unit test OK"	
	else
		echo "unit test KO"
	fi	
	rm -rf $filename.o $filename.s $filepath/a.out
