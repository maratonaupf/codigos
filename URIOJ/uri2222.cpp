/*
 * Leonardo Deliyannis Constantin
 * URI 2222 - Brincando com Conjuntos
 */

#include <stdio.h>
#define MAX 11234

typedef long long ll;

int countBits(ll x){
	int cnt = 0;
	for(ll i = 63; i >= 0; i--){
		if(x & (1LL<<i)) cnt++;
	}
	return cnt;
}

int main(){
	int T, N, Q;
	ll v[MAX]; 
	int i, m, x, y, op, ans;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		for(i = 1; i <= N; i++){
			v[i] = 0LL;
			scanf("%d", &m);
			while(m--){
				scanf("%d", &x);
				v[i] |= 1LL << (ll)x;
			}
		}
		scanf("%d", &Q);
		while(Q--){
			scanf("%d %d %d", &op, &x, &y);
			ans = countBits(op == 1 ? v[x] & v[y] : v[x] | v[y]);
			printf("%d\n", ans);
		}
	}
	return 0;
}
