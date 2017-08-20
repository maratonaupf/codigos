#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAX 110

int i, T, R, N, MW, V[MAX], W[MAX], memo[MAX][MAX];

int value(int id, int w){
	if(id == N || w == 0) return 0;
	if(memo[id][w] != -1) return memo[id][w];
	if(W[id] > w) return memo[id][w] = value(id + 1, w);
	return memo[id][w] = max(value(id + 1, w), V[id] + value(id + 1, w - W[id]));
}

int main(){
	scanf("%d", &T);
	while(scanf("%d", &N) != EOF){
		memset(memo, -1, sizeof(memo));
		for(i = 0; i < N; i++){
			scanf("%d %d", &V[i], &W[i]);
		}
		scanf("%d", &MW);
		scanf("%d", &R);
		printf("%s\n", value(0, MW) >= R ? 
			"Missao completada com sucesso" : "Falha na missao");
	}
	return 0;
}
