/*
 * Leonardo Deliyannis Constantin
 * CodeForces 489B - BerSU Ball
 */

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using std::sort;
#define MAX 112

int main(){
	int N, M, i, j;
	int b[MAX], g[MAX], ans;
	while(scanf("%d", &N) != EOF){
		for(i = 0; i < N; i++){
			scanf("%d", b+i);
		}
		scanf("%d", &M);
		for(i = 0; i < M; i++){
			scanf("%d", g+i);
		}
		sort(b, b+N);
		sort(g, g+M);
		ans = 0;
		int lj = -1;
		for(i = 0; i < N; i++){
			for(j = lj+1; j < M; j++){
				if(abs(b[i]-g[j]) <= 1){
					ans++;
					lj = j;
					break;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
