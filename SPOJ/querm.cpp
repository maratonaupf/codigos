#include<stdio.h>

int main(){
	int N, i, v, ganhador, teste = 0;
	while(scanf("%d", &N), N != 0){
		for(i = 1; i <= N; i++){
			scanf("%d", &v);
			if(v == i) ganhador = i;
		}
		printf("Teste %d\n", ++teste);
		printf("%d\n\n", ganhador);
	}
	return 0;
}
