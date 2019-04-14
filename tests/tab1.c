#include <stdio.h>
#include <inttypes.h>
int64_t square (int64_t a) {
    return a*a;
}

int64_t main(int64_t arg){
	int64_t tab[10];
	int64_t i ;
	for(i = 0; i < 10; i++) {
	    tab[i] = i;
	    putchar('\n');
	}
	tab[1] = 5;
	tab[2] = 6;
	return tab[1]+tab[2];
}
