#include<stdio.h>
#include<ctype.h>
#define MAX 112345

int main(void){
	int fila[MAX];
	int frente = 0, re = 0;
	int enfileirados = 0;
	char op;
	while(scanf(" %c", &op) != EOF){
		switch(toupper(op)){
			case 'E':
				scanf("%d", &fila[re]);
				printf("Enfileirou %d\n", fila[re++]);
				re %= MAX;
				enfileirados ++;
			break;
			case 'F':
				if(frente != re)
					printf("Frente: %d\n", fila[frente]);
				else printf("Fila vazia\n");
			break;
			case 'D':
				if(frente != re){
					printf("Desenfileirando %d\n", fila[frente++]);
					frente %= MAX;
				}
				else printf("Fila vazia\n");
				enfileirados--;
			break;
			case 'C':
				printf("Enfileirados: %d\n", enfileirados);
			break;
		}
	}
	while(frente != re){
		printf("Desenfileirando %d\n", fila[frente++]);
		frente %= MAX;
	}
	return 0;
}
