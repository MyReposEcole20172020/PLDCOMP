#include <inttypes.h>
#include <stdio.h>
int square(){
	putchar('a');
	char b = '\n';
	putchar(b);
	return 1;
}

int square();

int main(int arg){
	int tab[5];
	tab[0] = 10;
	int64_t b = 4;
    return tab[0] = b*square();
}
