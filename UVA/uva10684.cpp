/*
 * Leonardo Deliyannis Constantin
 * UVa 10684 - The jackpot
 */

#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 11234

int kadane(int *v, int n){
	int i, best = 0, sum = 0;
	for(i = 0; i < n; i++){
		sum = max(v[i], sum + v[i]);
		best = max(best, sum);
	}
	return best;
}

int main(){
	int N, v[MAX], i, ans;
	while(scanf("%d", &N), N){
		for(i = 0; i < N; i++){
			scanf("%d", v+i);
		}
		ans = kadane(v, N);
		if(ans > 0) printf("The maximum winning streak is %d.\n", ans);
		else printf("Losing streak.\n");
	}
	return 0;
}
