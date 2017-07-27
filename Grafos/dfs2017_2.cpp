#include <iostream>
#include <string.h>
#define MAX 112
using namespace std;

int N, E; // vértices e arestas
int LG[MAX][MAX]; // lista de adjacência
int d[MAX]; // qtd. de vizinhos
bool vis[MAX];

void mostraLista(){
	int i, u;
	for(u = 1; u <= N; u++){
		cout << "Vertice " << u << ":";
		for(i = 0; i < d[u]; i++){
			cout << " " << LG[u][i];
		}
		cout << "\n";
	}
}

void dfs(int s){
	int pilha[MAX], topo = -1;
	int u, w, i;
	vis[s] = true;
	pilha[++topo] = s;
	while(topo >= 0){
		u = pilha[topo--];
		cout << " " << u;
		for(i = 0; i < d[u]; i++){
			w = LG[u][i];
			if(!vis[w]){
				vis[w] = true;
				pilha[++topo] = w;
			}
		}
	}
}

int main(){
	int i, u, w;
	while(cin >> N >> E){
		memset(d, 0, sizeof(d));
		for(i = 1; i <= E; i++){
			cin >> u >> w;
			LG[u][d[u]++] = w;
		}
		mostraLista();
		memset(vis, 0, sizeof(vis));
		cout << "DFS:";
		for(u = 1; u <= N; u++){
			if(!vis[u]){
				dfs(u);
			}
		}
		cout << "\n";
	}
	return 0;
}
