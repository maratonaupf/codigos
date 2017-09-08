/*
 * Leonardo Deliyannis Constantin
 * UVa 558 - Wormholes
 */

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define INFTO ((int)1e9)

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int N, E;
vector<vii> LG;
vector<int> dist;

void bellman_ford(int s){
	int i, u, j, v, w;
	dist.assign(N, INFTO);
	dist[s] = 0;
	for(i = 0; i < N-1; i++){
		for(u = 0; u < N; u++){
			for(j = 0; j < (int)LG[u].size(); j++){
				v = LG[u][j].first;
				w = LG[u][j].second;
				dist[v] = min(dist[v], dist[u] + w);
}}}}

bool hasNegCycle(){
	int u, j, v, w;
	bool ret = false;
	for(u = 0; u < N; u++){
		for(j = 0; j < (int)LG[u].size(); j++){
			v = LG[u][j].first;
			w = LG[u][j].second;
			if(dist[v] > dist[u] + w){
				ret = true;
				break;
			}
		}
		if(ret) break;
	}
	return ret;
}

int main(){
	int c, i, u, v, w;
	scanf("%d", &c);
	while(c--){
		scanf("%d %d", &N, &E);
		LG.assign(N, vii());
		for(i = 0; i < E; i++){
			scanf("%d %d %d", &u, &v, &w);
			LG[u].push_back(ii(v, w));
		}
		bellman_ford(0);
		printf("%spossible\n", hasNegCycle() ? "" : "not ");
	}
	return 0;
}
