/*
 * Leonardo Deliyannis Constantin
 * URI 1487 - Six Flags
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAXN 112
#define MAXW 612

int N, T;
int W[MAXN], V[MAXN];
int memo[MAXN][MAXW];

inline int max(int a, int b, int c){
	return max(a, max(b, c));
}

int pd(int id, int w){
	if(id == N || w == 0) return 0;
	if(memo[id][w] != -1) return memo[id][w];
	if(W[id] > w) return memo[id][w] = pd(id+1, w);
	return memo[id][w] = 
		max(pd(id+1, w), pd(id+1, w - W[id]) + V[id],
			pd(id, w - W[id]) + V[id]);
}

int main(){
	int i, tc = 0;
	while(scanf(" %d %d", &N, &T), !(N == 0 && T == 0)){
		for(i = 0; i < N; i++){
			scanf(" %d %d", &W[i], &V[i]);
		}
		memset(memo, -1, sizeof(memo));
		printf("Instancia %d\n%d\n\n", ++tc, pd(0, T));
	}
	return 0;
}
