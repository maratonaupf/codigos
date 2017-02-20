#include<stdio.h>
#include<queue>
#include<utility>
#include<vector>
#include<map>
#include<algorithm>
#define INFTO 112345678
#define DEBP

using namespace std;

typedef pair<int, int> ii;
typedef map<short, int> mii;
typedef vector<mii> grafo;

int N, E;
grafo LG;

vector<int> dist;
void dijkstra(int s) {
	int u, w, z, poss;
	mii::iterator i, j;
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	dist.assign(N+1, INFTO);
	dist[s] = 0;
	pq.push(ii(dist[s], s));
	while(!pq.empty()){
		u = pq.top().second; pq.pop();
		for(i = LG[u].begin(); i != LG[u].end(); ++i){
			w = i->first;
			for(j = LG[w].begin(); j != LG[w].end(); ++j){
				z = j->first;
				//poss = dist[u] + i->second + j->second;
				poss = dist[u] + LG[u][w] + LG[w][z];
				if(dist[z] > poss){
					dist[z] = poss;
					pq.push(ii(dist[z], z));
				}
			}
		}
	}
}

int main(void){
	int i, u, w, peso;
	while(scanf("%d %d", &N, &E) != EOF){
		LG.resize(N+1);
		for(i = 1; i <= E; i++){
			scanf("%d %d %d", &u, &w, &peso);
			LG[u][w] = LG[w][u] = peso;
		}
		dijkstra(1);
		printf("%d\n", dist[N] != INFTO ? dist[N] : -1);
		LG.clear();
	}
	return 0;
}
