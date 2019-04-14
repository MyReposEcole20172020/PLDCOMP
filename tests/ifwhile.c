#include <stdio.h>
#include <inttypes.h>
int main(){
	int i=0;
	int j=10;
	if(j>0){
		while (i<=10){
			if(i<5){
				putchar('x');
			}
			i++;
		}
	}
	return i;
}
