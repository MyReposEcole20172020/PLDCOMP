#include <stdio.h>
#include <inttypes.h>

int square (int a) {
    return a*a;
}

int main(int arg){
	int x = sizeof(int);
	int z = sizeof(int);
	int y = 5;
	z |= y;
	int a = 7; 
	if(square(0)){
		putchar('a');
		return 1;
	}else if(3 > 4){
		putchar('b');
	}else if(3 > 2){
		if(a > 6){
			int x;
			for(x = 0; x < 3; x++){
				int a = 99;
				putchar(a);
			}
			int tab[5];
			x = 0;
			while(x < 5){
				tab[x] = x+97;
				putchar(tab[x]);
				x++;
			}
		}
	}else{
		putchar('c');
	}
    return x+a;
}
