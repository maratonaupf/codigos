/*
 * Leonardo Deliyannis Constantin
 * canhao
 */

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 212

int N, W[MAX], V[MAX], memo[MAX][MAX];

int pd(int id, int w){
	if(id == N || w == 0) return 0;
	if(memo[id][w] != -1) return memo[id][w];
	if(W[id] > w) return memo[id][w] = pd(id+1, w);
	return memo[id][w] = 
		max(pd(id+1, w), pd(id+1, w-W[id]) + V[id]);
}

int main(){
	int M, K, R, i, ans;
	scanf(" %d", &M);
	while(M--){
		scanf(" %d", &N);
		for(i = 0; i < N; i++){
			scanf(" %d %d", &V[i], &W[i]);
		}
		scanf(" %d", &K);
		scanf(" %d", &R);
		memset(memo, -1, sizeof(memo));
		ans = pd(0, K);
		if(ans >= R)
			printf("A resistencia do castelo %d nao suportou o ataque da missao %d\n", R, ans);
		else printf("Missao falhou\n");
	}
	return 0;
}
