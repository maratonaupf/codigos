#include<stdio.h>

int main(){
	int N, teste = 0;
	while(scanf("%d", &N), N != 0){
		printf("Teste %d\n", ++teste);
		printf("%d\n\n", (1 << N) - 1);
	}
	return 0;
}
