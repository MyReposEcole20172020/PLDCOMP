int square (int a) {
    return a*a;
}

int main(int arg){
	int tab[10];
	int i ;
	for(i = 0; i < 10; i++) {
	    tab[i] = i;
	    putchar('\n');
	}
	tab[1] = 5;
	tab[2] = 6;
	return tab[1]+tab[2];
}
