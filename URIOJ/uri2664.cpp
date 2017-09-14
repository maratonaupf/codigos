/*
 * Leonardo Deliyannis Constantin
 * URI 2664 - Ginástica (Maratona SBC 2017)
 */

#include <stdio.h>
#include <string.h>
// fine P 1123456789
#define P 1000000007
#define MAXT 51
#define MAXN 112345
typedef long long ll;

int T, M, N;
int memo[MAXT][MAXN];

// (a [] b) % c == ((a % c) [] (b % c)) % c

int pd(int t, int n){
	if(n < M || n > N) return 0;
	if(memo[t][n] != -1) return memo[t][n];
	if(t <= 1) return memo[t][n] = t;
	return memo[t][n] = 
		((pd(t-1, n-1) % P) + (pd(t-1, n+1) % P)) % P;
}

int main(){
	int i, ans;
	while(scanf("%d %d %d", &T, &M, &N) != EOF){
		memset(memo, -1, sizeof(memo));
		ans = 0;
		for(i = M; i <= N; i++){
			ans += pd(T, i) % P;
			ans %= P;
		}
		printf("%d\n", ans);
	}
	return 0;
}
