/*
 * Leonardo Deliyannis Constantin
 * http://br.spoj.com/problems/BIT/
 */

#include <stdio.h>

const int val[4] = {50, 10, 5, 1};

int main(){
	int V, i, T = 0;
	while(scanf("%d", &V), V != 0){
		printf("Teste %d\n", ++T);
		for(i = 0; i < 4; i++){
			printf("%d%c", V / val[i], i < 3 ? ' ' : '\n');
			V %= val[i];
		}
		printf("\n");
	}
	return 0;
}
