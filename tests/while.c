#include <inttypes.h>
#include <stdio.h>
int main(){
	char i;
	i='A';
	
	while(i<'Z'+1)	{
			putchar(i);
			i=i+1;
		} 
	putchar('\n');
	return 20;
}
