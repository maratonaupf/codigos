/*
 * Leonardo Deliyannis Constantin
 * URI 1931 - Mania de Par
 */

#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
#define INFTO ((int)1e9)

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int C, V;
vector<vii> LG;
vi dist;

void dijkstra(int s){
	dist.assign(C, INFTO);
	dist[s] = 0;
	priority_queue<ii, vector<ii>, greater<ii> > Q;
	Q.push(ii(0, s));
	while(!Q.empty()){
		int u = Q.top().second; Q.pop();
		for(int i = 0; i < (int)LG[u].size(); i++){
			int v = LG[u][i].first;
			for(int j = 0; j < (int)LG[v].size(); j++){
				int y = LG[v][j].first;
				int w = LG[v][j].second + LG[u][i].second;
				if(dist[y] > dist[u] + w){
					dist[y] = dist[u] + w;
					Q.push(ii(dist[y], y));
				}
			}
		}
	}
}

int main(){
	int i, u, v, w;
	while(scanf("%d %d", &C, &V) != EOF){
		LG.assign(C, vii());
		for(i = 0; i < V; i++){
			scanf("%d %d %d", &u, &v, &w);
			u--; v--;
			LG[u].push_back(ii(v, w));
			LG[v].push_back(ii(u, w));
		}
		dijkstra(0);
		printf("%d\n", dist[C-1] == INFTO ? -1 : dist[C-1]);
	}
	return 0;
}
