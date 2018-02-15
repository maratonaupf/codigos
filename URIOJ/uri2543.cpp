/*
 * Leonardo Deliyannis Constantin
 * URI 2543 - Jogatina UFPR
 */

#include <stdio.h>

int main(){
	int N, id, x, j, ans;
	while(scanf("%d %d", &N, &id) != EOF){
		ans = 0;
		while(N--){
			scanf("%d %d", &x, &j);
			if(x == id && j == 0) ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
