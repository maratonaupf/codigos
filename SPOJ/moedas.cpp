/*
 * Leonardo Deliyannis Constantin
 * http://br.spoj.com/problems/MOEDAS/
 */

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define INFTO 112345678
#define MAX 112
#define TAM 50001

int N;
int v[MAX];
int memo[TAM];
bool ok[TAM];

int coins(int sum){
	if(sum < 0) return INFTO;
	if(sum == 0) return 0;
	if(ok[sum]) return memo[sum];
	int best = INFTO;
	for(int i = 0; i < N; i++){
		best = min(best, coins(sum - v[i]) + 1);
	}
	memo[sum] = best;
	ok[sum] = true;
	return best;
}

int main(){
	int M, i, ans;
	while(scanf("%d", &M), M){
		scanf("%d", &N);
		for(i = 0; i < N; i++){
			scanf("%d", &v[i]);
		}
		memset(ok, 0, sizeof(ok));
		ans = coins(M);
		(ans != INFTO) ? printf("%d\n", ans) : printf("Impossivel\n");
	}
	return 0;
}
