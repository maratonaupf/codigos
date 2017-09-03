/*
 * Leonardo Deliyannis Constantin
 * URI 1940 - Jogo da Estratégia
 */

#include <stdio.h>
#include <string.h>
#define MAX 512

int main(){
	int J, R, r, i, v[MAX], aux, ans;
	while(scanf("%d %d", &J, &R) != EOF){
		memset(v, 0, sizeof(v));
		for(r = 0; r < R; r++){
			for(i = 0; i < J; i++){
				scanf("%d", &aux);
				v[i] +=  aux;
			}
		}
		ans = 0;
		for(i = 0; i < J; i++){
			if(v[i] >= v[ans]) ans = i;
		}
		printf("%d\n", ans + 1);
	}
	return 0;
}
