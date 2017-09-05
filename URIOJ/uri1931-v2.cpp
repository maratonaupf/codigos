#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;
#define pb push_back
#define INFTO (int(1e9))

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int N, E;
vector<vii> LG;
vector<int> dist;

int dijkstra(int s, int t){
	int u, v, w, i, j, peso;
	dist.assign(N+1, INFTO);
	dist[s] = 0;
	priority_queue<ii, vector<ii>, greater<ii> > Q;
	Q.push(ii(0, s));
	while(!Q.empty()){
		u = Q.top().second; Q.pop();
		for(i = 0; i < (int)LG[u].size(); i++){
			v = LG[u][i].first;
			for(j = 0; j < (int)LG[v].size(); j++){
				w = LG[v][j].first;
				peso = dist[u] + LG[u][i].second +
					LG[v][j].second;
				if(dist[w] > peso){
					dist[w] = peso;
					Q.push(ii(peso, w));
				}
			}
		}
	}
	return dist[t];
}

int main(){
	int i, a, b, p;
	while(scanf("%d %d", &N, &E) != EOF){
		LG.assign(N+1, vii());
		for(i = 0; i < E; i++){
			scanf("%d %d %d", &a, &b, &p);
			LG[a].pb(ii(b, p));
			LG[b].pb(ii(a, p));
		}
		int ans = dijkstra(1, N);
		printf("%d\n", ans != INFTO ? ans : -1);
	}
	return 0;
}
