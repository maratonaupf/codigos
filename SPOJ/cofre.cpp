/*
 * Leonardo Deliyannis Constantin
 * http://br.spoj.com/problems/COFRE/
 */

#include <stdio.h>

int main(){
	int T, N, c1, c2, dif;
	T = 0;
	while(scanf("%d", &N), N != 0){
		printf("Teste %d\n", ++T);
		dif = 0;
		while(N--){
			scanf("%d %d", &c1, &c2);
			dif += c1 - c2;
			printf("%d\n", dif);
		}
		printf("\n");
	}
	return 0;
}