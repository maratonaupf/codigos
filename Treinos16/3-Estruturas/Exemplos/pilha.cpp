#include<stdio.h>
#include<ctype.h>
#define MAX 112345

int main(void){
	char pilha[MAX][50];
	int topo = -1;
	char op;
	while(scanf(" %c", &op) != EOF){
		switch(toupper(op)){
			case 'E':
				scanf("%s", pilha[++topo]);
				printf("Empilhou %s\n", pilha[topo]);
			break;
			case 'T':
				if(topo > -1)
					printf("Topo: %s\n", pilha[topo]);
				else printf("Pilha vazia\n");
			break;
			case 'D':
				if(topo > -1)
					printf("Desempilhando %s\n", pilha[topo--]);
				else printf("Pilha vazia\n");
			break;
		}
	}
	while(topo > -1){
		printf("Desempilhando %s\n", pilha[topo--]);
	}
	return 0;
}
