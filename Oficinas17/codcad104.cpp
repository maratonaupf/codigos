#include<stdio.h>

int main(void){
	int a, b, c;
	while(scanf("%d %d %d", &a, &b, &c) != EOF){
		printf("%c\n", (a == b || a == c || b == c ||
			a == b+c || b == a+c || c == a+b) ? 'S' : 'N');
	}
	return 0;
}
