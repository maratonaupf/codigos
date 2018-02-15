/*
 * Leonardo Deliyannis Constantin
 * URI 2221 - Batalha de Pomekons
 */

#include <stdio.h>

int main(){
	int T, B, a, d, l, v[2], i;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &B);
		for(i = 0; i < 2; i++){
			scanf("%d %d %d", &a, &d, &l);
			v[i] = (a+d)/2 + (l&1 ? 0 : B);
		}
		printf("%s\n", v[0] > v[1] ? "Dabriel" : 
			v[0] == v[1] ? "Empate" : "Guarte");
	}
	return 0;
}
