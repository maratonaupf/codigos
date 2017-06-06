/*
 * Leonardo Deliyannis Constantin
 * UVa 11450 - Wedding shopping
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define INFTO 1e9

typedef vector<int> vi;
typedef vector<vi> vvi;

int M, C;
vvi price;
vvi memo;

int pd(int money, int g){
	if(money < 0) return -INFTO;
	if(g == C) return M - money;
	if(memo[money][g] != -1) return memo[money][g];
	int ans = -1;
	for(int model : price[g]){
		ans = max(ans, pd(money - model, g+1));
	}
	return memo[money][g] = ans;
}

int main(){
	int N, K, i, j;
	int ans;
	scanf("%d", &N);
	while(N--){
		scanf("%d %d", &M, &C);
		price.assign(C, vi());
		for(i = 0; i < C; i++){
			scanf("%d", &K);
			price[i].assign(K, 0);
			for(j = 0; j < K; j++){
				scanf("%d", &price[i][j]);
			}
		}
		memo.assign(M+1, vi(C, -1));
		ans = pd(M, 0);
		(ans >= 0) ? printf("%d\n", ans) : printf("no solution\n");
	}
	return 0;
}
