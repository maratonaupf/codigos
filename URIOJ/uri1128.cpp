#include<stdio.h>
#include<utility>
#include<vector>
#include<algorithm>
#define UNVISITED (-1)
//#define DEBP

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> grafo;
typedef vector<ii> vii;

int N, E;

vi dfsNum, S;
int numSCC; 

vi dfsLow, visited;
int dfsNC;
void tarjanSCC(grafo &LG, int u){
	int j, v;
	dfsNum[u] = dfsLow[u] = dfsNC++;
	S.push_back(u);
	visited[u] = 1;
	for(j = 0; j < (int)LG[u].size(); j++){
		v = LG[u][j];
		if(dfsNum[v] == UNVISITED){
			tarjanSCC(LG, v);
		}
		if(visited[v]){
			dfsLow[u] = min(dfsLow[u], dfsLow[v]);
		}
	}
	
	if(dfsLow[u] == dfsNum[u]){
		++numSCC;
		#ifdef DEBP
		printf("SCC %d:", numSCC);
		#endif
		while(true){
			v = S.back();
			S.pop_back();
			visited[v] = 0;
			#ifdef DEBP
			printf(" %d", v);
			#endif
			if(u == v) break;
		}
		#ifdef DEBP
		printf("\n");
		#endif
	}
}

void tarjan(grafo &LG){
	dfsNum.assign(N+1, UNVISITED);
	dfsLow.assign(N+1, 0);
	visited.assign(N+1, 0);
	dfsNC = numSCC = 0;
	for(int vert = 1; vert <= N; vert++){
		if(dfsNum[vert] == UNVISITED){
			tarjanSCC(LG, vert);
		}
	}
}

int main(void){
	int u, w, dir, e;
	while(scanf("%d %d", &N, &E), N){
		grafo LG(N+1);
		for(e = 1; e <= E; e++){
			scanf("%d %d %d", &u, &w, &dir);
			LG[u].push_back(w);
			if(dir == 2) LG[w].push_back(u);
		}
		tarjan(LG);
		printf("%d\n", numSCC == 1);
		LG.clear();
		S.clear();
	}
	return 0;
}
