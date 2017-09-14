/*
 * Leonardo Deliyannis Constantin
 * URI 2663 - Fase (Maratona SBC 2017)
 */

#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 1123

bool revcmp(const int &a, const int &b) {
	return a > b;
}

int main(){
	int N, K, v[MAX], i;
	int ans;
	while(scanf("%d", &N) != EOF){
		scanf("%d", &K);
		for(i = 0; i < N; i++){
			scanf("%d", &v[i]);
		}
		sort(v, v+N, revcmp);
		ans = K;
		while(v[ans-1] == v[ans]) ans++;
		printf("%d\n", ans);
	}
	return 0;
}
