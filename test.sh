#!/bin/bash
	unitaire() {
		filepath=$(dirname "$1")
		length=$(echo -n $1 | wc -c)
		length=$(($length-2))
		filename=$(echo $1|cut -c9-$length)
		cat "./tests/$filename.c"
		rm -rf $filepath/$filename.o $filepath/$filename.s $filepath/$filename.out
		make --no-print-directory back file=./$filename path=./tests
		output2=$($filepath"/a.out")
		return2=$(echo $?)
		echo "\noutput comp:"$output2
		echo "return value comp:"$return2"\n"
		cd $filepath
		gcc $filename.c -o ./a.out
		output1=$(./a.out)
		return1=$(echo $?)
		echo "\noutput gcc:"$output1
		echo "return value gcc:"$return1"\n"
		if [ "$output1" = "$output2" ] && [ "$return1" = "$return2" ] ;then
			return 1	
		else
			return 0
		fi	
	}
	rm -rf ./*.o ./*.s out.pdf a.out testResult.txt
	shell_folder=$(cd "$(dirname .)";pwd)
	if [ -f "./Main.exe" ];then
		echo ""
	else
		make
	fi	
	nbTotal=0
	nbValide=0
	nbNon=0
	for i in $(find "./tests" -name "*.c"|sort -t "\0" -n);
	do 
		nbTotal=$((nbTotal+1))
		filename=$(echo $i|cut -c3-)
		filename=$(echo "./"$filename)
		unitaire $filename
		result="$?"
		if [ $result -eq 1 ]; 
			then nbValide=$(($nbValide+1))
			echo "OK"
		else
			nbNon=$(($nbNon+1))
			echo "KO"
		fi
		echo ""
		cd ~
		cd $shell_folder
	done
	cd ~
	cd $shell_folder/tests
	echo "total:       "$nbTotal	
	echo "valide:      "$nbValide
	echo "non valide:  "$nbNon
	echo "total:       "$nbTotal>>testResult.txt	
	echo "valide:      "$nbValide>>testResult.txt
	echo "non valide:  "$nbNon>>testResult.txt
	rm -rf *.o *.s a.out
	
