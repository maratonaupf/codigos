/*
 * Leonardo Deliyannis Constantin
 * Maratona SBC 2016 - Isósceles
 */

#include <stdio.h>
#include <vector>
using namespace std;

int main(){
	int N, i, ans;
	while(scanf("%d", &N) != EOF){
		vector<int> h(N, 0);
		vector<int> esq(N, -1);
		vector<int> dir(N, -1);
		for(i = 0; i < N; i++){
			scanf("%d", &h[i]);
			esq[i] = (i > 0) ? min(esq[i-1] + 1, h[i]) : 1;
		}
		ans = 0;
		for(i = N-1; i >= 0; i--){
			dir[i] = (i < N-1) ? min(dir[i+1] + 1, h[i]) : 1;
			ans = max(ans, min(esq[i], dir[i]));
		}
		printf("%d\n", ans);
	}
	return 0;
}
