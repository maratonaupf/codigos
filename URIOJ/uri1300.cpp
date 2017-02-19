#include<stdio.h>

int main(void){
	int N;
	while(scanf("%d", &N) != EOF){
		printf("%c\n", N%6 == 0 ? 'Y' : 'N');
	}
	return 0;
}
