#!/bin/sh
	rm -rf ./*.o ./*.s out.pdf a.out
	filename=$(echo $1|cut -d . -f1)
	cat $filename.c
	make build file=$filename ||exit "$$?"
	echo "output:"	
	./a.out
	echo "\nreturn:\n"$?
