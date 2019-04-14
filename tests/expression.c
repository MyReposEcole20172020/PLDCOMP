#include <stdio.h>
int main(int arg){
	int x,y;
	x=2+3;
	y = x-1;
	y++;
	--y;
	y+=x;
	y-=x;
	y*=x;
	y/=x;
	y = y + x;
	y = 2 * (x + 3);
	x = x * y;
	char a='a';
	putchar(a);
	int tab[3];
	tab[0] = x/y;
	return tab[0]+2;
}
