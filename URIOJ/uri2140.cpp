#include<stdio.h>

int notas[] = {2, 5, 10, 20, 50, 100};

int main(void){
	int N, M, i, cont, troco;
	while(scanf("%d %d", &N, &M), N){
		cont = 0;
		troco = M - N;
		for(i = 5; i >= 0; i--){
			cont += troco / notas[i];
			troco %= notas[i];
		}
		printf("%spossible\n", cont == 2 ? "" : "im");
	}
	return 0;
}
