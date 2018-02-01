/*
 * Leonardo Deliyannis Constantin
 * UVa 280 - Vertex
 */

#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;
#define MAX 112

int N;
int LG[MAX][MAX];
int d[MAX];
int vis[MAX];
int unvis;

void dfs(int s){
	memset(vis, 0, sizeof(vis));
	int u, v, i;
	stack<int> Q;
	Q.push(s);
	while(!Q.empty()){
		u = Q.top(); Q.pop();
		for(i = 0; i < d[u]; i++){
			v = LG[u][i];
			if(!vis[v]){
				vis[v] = true;
				unvis--;
				Q.push(v);
			}
		}
	}
}

int main(){
	int u, v, q;
	while(scanf("%d", &N), N){
		memset(d, 0, sizeof(d));
		while(scanf("%d", &u), u){
			while(scanf("%d", &v), v){
				LG[u][d[u]++] = v;
			}
		}
		scanf("%d", &q);
		while(q--){
			scanf("%d", &u);
			unvis = N;
			dfs(u);
			printf("%d", unvis);
			for(v = 1; v <= N; v++){
				if(!vis[v])
					printf(" %d", v);
			}
			printf("\n");
		}
	}
	return 0;
}
