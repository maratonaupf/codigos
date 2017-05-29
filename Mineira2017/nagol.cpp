/*
 * Leonardo Deliyannis Constantin
 * Maratona Mineira 2017 - Problema L: Nagol
 */

#include <stdio.h>

int main(){
	int C, X, Y;
	while(scanf("%*d %d %d %d\n", &C, &X, &Y) != EOF){
		printf("%s\n", (C&1 && (X+Y)&1) || (!(C&1) && Y&1) ? "Esquerda" : "Direita");
	}
	return 0;
}
