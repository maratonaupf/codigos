/*
 * Leonardo Deliyannis Constantin
 * URI 1128 - Ir e Vir
 */

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

enum color { white = -1, black = 1};
typedef vector<int> vi;
typedef pair<int, int> ii;

int N, M;
vector<vi> LG;
vi S, num, low, vis;
int dfs, scc;

void tarjan(int u){
	low[u] = num[u] = dfs++;
	S.push_back(u);
	vis[u] = 1;
	for(int i = 0; i < (int)LG[u].size(); i++){
		int v = LG[u][i];
		if(num[v] == white){
			tarjan(v); 
		}
		if(vis[v]){
			low[u] = min(low[u], low[v]);
		}
	}

	if(low[u] == num[u]){
		++scc;
	}
}

int isConnected(){
	S.clear();
	num.assign(N, white); 
	low.assign(N, 0);
	vis.assign(N, 0);
	dfs = scc = 0;
	for(int u = 0; u < N; u++){
		if(num[u] == white)
			tarjan(u);
	}
	return scc == 1;
}

int main(){
	int i, u, v, w;
	while(scanf("%d %d", &N, &M), N){
		LG.assign(N, vi());
		for(i = 0; i < M; i++){
			scanf("%d %d %d", &u, &v, &w);
			u--; v--;
			LG[u].push_back(v);
			if(w == 2) LG[v].push_back(u);
		}
		printf("%d\n", isConnected());
	}
	return 0;
}
