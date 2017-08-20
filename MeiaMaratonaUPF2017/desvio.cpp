#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
using namespace std;
#define INFTO ((int)1e9)

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef map<int, int> mii;

int N, E, C, K;
vector<map<int, int> > LG; // lista de adjacência

int dijkstra(int s, int t){
	int u, v, peso;
	vi dist(N, INFTO);
	dist[s] = 0;
	priority_queue<ii, vector<ii>, greater<ii> > Q;
	Q.push(ii(0, s));
	while(!Q.empty()){
		u = Q.top().second;
		Q.pop();
		for(auto it = LG[u].begin(); it != LG[u].end(); ++it){
			v = it->first, peso = it->second;
			if(dist[v] > dist[u] + peso){
				dist[v] = dist[u] + peso;
				Q.push(ii(dist[v], v));
			}
		}
	}
	return dist[t];
}

inline bool inRoute(int vtx){ return vtx < C; }
inline void addEdge(int u, int v, int peso){ LG[u][v] = peso; }

int main(){
	int u, v, peso;
	while(scanf("%d %d %d %d", &N, &E, &C, &K), N != 0){
		LG.assign(N, mii());
		for(int i = 0; i < E; i++){
			scanf("%d %d %d", &u, &v, &peso);
			// só adiciona aresta de fora da rota para dentro da rota
			if(u < v) swap(u, v);
			addEdge(u, v, peso);
			// se nenhum vértice estiver na rota
			// ou ambos forem vértices consecutivos da rota,
			// adiciona a aresta de volta
			if((!inRoute(u) && !inRoute(v)) ||
				(inRoute(u) && inRoute(v) && abs(u-v) == 1)){
				addEdge(v, u, peso);
			}
		}
		printf("%d\n", dijkstra(K, C-1));
	}
	return 0;
}
