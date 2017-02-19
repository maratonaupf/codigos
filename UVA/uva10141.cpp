#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define TAM 82

int main(void){
	int N, P, i, j, met, caso = 0;
	char name[TAM], bestName[TAM], trash[TAM];
	double compliance, bestComp;
	double price, bestPrice;
	while(scanf("%d %d\n", &N, &P), N != 0){
		caso++;
		/* todos os requerimentos cumpridos estarao na
		 * lista, entao nao eh necessario armazena-los */
		for(i = 0; i < N; i++) fgets(trash, TAM, stdin);
		for(i = 0; i < P; i++){
			fgets(name, TAM, stdin);
			scanf("%lf %d\n", &price, &met);
			/* motivo explicado acima */
			for(j = 0; j < met; j++) fgets(trash, TAM, stdin);
			compliance = (double)met / (double)N;
			if(i == 0 || compliance > bestComp 
			|| (compliance == bestComp && price < bestPrice)){
				strcpy(bestName, name);
				bestComp = compliance;
				bestPrice = price;
			}
		}
		if(caso > 1) printf("\n");
		printf("RFP #%d\n", caso);
		printf("%s", bestName);
	}
	return 0;
}
