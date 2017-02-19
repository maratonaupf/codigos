#include<stdio.h>
#include<math.h>

double juroSimples(double valor, double taxa, int prazo){
	return (valor * taxa) * (double) prazo;
}

double juroComposto(double valor, double taxa, int prazo){
	double acum = valor;
	for(int i = 0; i < prazo; i++){
		acum += taxa * acum;
	}
	return acum - valor;
}

int main(void){
	double valor, taxa; 
	double simples, composto;
	int prazo;
	
	while(scanf("%lf", &valor) != EOF){
		scanf("%lf", &taxa);
		scanf("%d", &prazo);
		
		simples = juroSimples(valor, taxa, prazo);
		composto = juroComposto(valor, taxa, prazo);
		
		printf("DIFERENCA DE VALOR = %.2lf\n", fabs(simples - composto));
		printf("JUROS SIMPLES = %.2lf\n", simples);
		printf("JUROS COMPOSTO = %.2lf\n", composto);
	}
	return 0;
}
