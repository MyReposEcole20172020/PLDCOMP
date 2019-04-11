#!/bin/sh
	rm -rf ./*.o ./*.s out.pdf a.out
	find ./ -name "*.c"|sort -t "\0" -n| while read i
	do 
		filename=$(echo $i|cut -c3-)
		echo $filename
		sh ./out.sh $filename
		echo "\n"
	done
	echo "fini!"
