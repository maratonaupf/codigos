/*
 * Leonardo Deliyannis Constantin
 * Maratona Mineira 2017 - Problema A: Ações
 */

#include <stdio.h>

int main(){
	int D, I, X, F;
	while(scanf("%d %d %d %d", &D, &I, &X, &F) != EOF){
		I += F&1 ? D&1 ? X : -X : 0;
		printf("%d\n", I);
	}
	return 0;
}
