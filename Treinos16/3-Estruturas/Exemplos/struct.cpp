#include<stdio.h>

struct carro{
	//char placa[8];
	char nome[50];
	int ano;
};

int main(void){
	carro c;
	//while(scanf("%s %d", c.nome, c.placa) != EOF){
	while(fgets(c.nome, 50, stdin) != NULL){
		scanf("%d", &c.ano);
		getchar();
		printf("Carro: %s", c.nome);
		//printf("Placa: %s\n", c.placa);
		printf("Ano: %d\n", c.ano);
	}
	return 0;
}
