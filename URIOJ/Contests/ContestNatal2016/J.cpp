#include<stdio.h>

int main(void){
	int N;
	while(scanf("%d", &N) != EOF){
		printf("Feliz nat");
		while(N--) putchar('a');
		printf("l!\n");
	}
	return 0;
}
