/*
 * Leonardo Deliyannis Constantin
 * http://br.spoj.com/problems/ASSALTMG/
 */

#include <stdio.h>
#include <string.h>
#define INFTO 112345678U
#define contaBits(_x) (__builtin_popcount(_x))

int main(){
	int T, M, D;
	int C, i, key, mask;
	unsigned v[20], ans, keys;
	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &M, &D);
		memset(v, 0, sizeof(v));
		for(i = 0; i < D; i++){
			scanf("%d", &C);
			while(C--){
				scanf("%d", &key);
				v[i] |= 1<<key;
			}
		}
		ans = INFTO;
		for(mask = 0; mask < (1 << D); mask++){
			keys = 0U;
			for(i = 0; i < D; i++){
				if(mask & (1 << i)){
					keys |= v[i];
				}
			}
			if(contaBits(keys) >= M && contaBits(mask) < ans) 
				ans = contaBits(mask);
		}
		ans != INFTO ? printf("%d\n", ans) : printf("Desastre!\n");
	}
	return 0;
}
