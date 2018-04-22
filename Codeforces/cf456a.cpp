/*
 * Leonardo Deliyannis Constantin
 * CodeForces 456A - Laptops
 */

#include <stdio.h>

int main(){
	int N, i;
	int p, q;
	bool ans;
	while(scanf("%d", &N) != EOF){
		ans = false;
		for(i = 0; i < N; i++){
			scanf("%d %d", &p, &q);
			if(p != q) ans = true;
		}
		printf("%s Alex\n", ans ? "Happy" : "Poor");
	}
	return 0;
}
