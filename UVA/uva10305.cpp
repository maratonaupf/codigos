/*
 * Leonardo Deliyannis Constantin
 * UVa 10305 - Ordering Tasks
 */

#include <stdio.h>
#include <string.h>
#include <vector>
#include <stack>
#include <cassert>
using namespace std;
#define MAX 112

typedef vector<int> vi;

int V, E;
int LG[MAX][MAX];
int d[MAX];
bool vis[MAX];

vi ts;

void dfs2(int u){
	int w, i;
	vis[u] = true;
	for(i = 0; i < d[u]; i++){
		w = LG[u][i];
		if(!vis[w]){
			dfs2(w); }}
	ts.push_back(u);
}

int main(){
	int u, w, i;
	while(scanf("%d %d\n", &V, &E), V != 0 || E != 0){
		memset(d, 0, sizeof(d));
		for(i = 0; i < E; i++){
			scanf("%d %d\n", &u, &w);
			LG[u][d[u]++] = w;
		}
		memset(vis, 0, sizeof(vis));
		for(u = 1; u <= V; u++){
			if(!vis[u]){
				dfs2(u); }}
		for(i = V-1; i >= 0; i--){
			printf("%d%c", ts[i], i > 0 ? ' ' : '\n');
		}
		ts.clear();
	}
	return 0;
}
