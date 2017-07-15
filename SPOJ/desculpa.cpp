/*
 * Leonardo Deliyannis Constantin
 * http://br.spoj.com/problems/DESCULPA/
 */

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 1123
#define MAXF 51

int W, N;
int v[MAXF], w[MAXF];
int m[MAXF][MAX];

int pd(int i, int W){
	if(m[i][W] != -1) return m[i][W];
	if(i == 0) return m[i][W] = 0;
	if(w[i] > W) return m[i][W] = pd(i-1, W);
	//if(w[i] <= W)
	return m[i][W] = max(pd(i-1, W), pd(i-1, W-w[i]) + v[i]);
}

int main(){
	int i, T = 0;
	while(scanf("%d %d", &W, &N), W != 0 && N != 0){
		for(i = 1; i <= N; i++){
			scanf("%d %d", w+i, v+i); 
		}
		memset(m, -1, sizeof(m));
		printf("Teste %d\n", ++T);
		printf("%d\n\n", pd(N, W));
	}
	return 0;
}
