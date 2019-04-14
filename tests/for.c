#include <stdio.h>
#include <inttypes.h>
int64_t main(){
	int64_t i,j,k;
	for(i=0;i<3;i++){
		putchar('i');
	}
	for(j=3;j>0;j--){
		putchar('j');
	}
	for(k=3;k>0;k=k-1){
		putchar('k');
	}

	putchar('a');
	return i;
}
