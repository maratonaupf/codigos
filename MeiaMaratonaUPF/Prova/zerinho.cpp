#include<stdio.h>

int main(void){
	int a, b, c;
	// EOF em C é mais simples ^^
	while(scanf("%d %d %d", &a, &b, &c) != EOF){
		// De novo com os ternários...
		printf("%c\n", (a != b && a != c) ? 'A' : 
			(b != a && b != c) ? 'B' : 
			(c != b && c != a) ? 'C' : '*');
	}
	return 0;
}

