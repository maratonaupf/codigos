#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<string.h>
#define MAX 512
#define INFTO 1123456789
#define DEBP

using namespace std;

int N, E, I;
typedef map<int, vector<int> > grafo;
int d[MAX];
int dist[MAX];
grafo LG;

int bfs(int s, int t){
	int i, u, w;
	for(u = 0; u < MAX; u++){
		dist[u] = INFTO;
	}
	dist[s] = 0;
	queue<int> fila;
	fila.push(s);
	#ifdef DEBP
	cout << s;
	#endif
	while(!fila.empty()){
		u = fila.front();
		fila.pop();
		for(i = 0; i < d[u]; i++){
			w = LG[u][i];
			if(dist[w] == INFTO){
				#ifdef DEBP
				cout << " " << w;
				#endif
				dist[w] = dist[u] + 1;
				fila.push(w);
			}
		}
	}
	#ifdef DEBP
	cout << endl;
	#endif
	return dist[t];
}

int dfs(int s, int t){
	int i, u, w;
	for(u = 0; u < MAX; u++){
		dist[u] = INFTO;
	}
	dist[s] = 0;
	stack<int> pilha;
	pilha.push(s);
	#ifdef DEBP
	cout << s;
	#endif
	while(!pilha.empty()){
		u = pilha.top();
		pilha.pop();
		for(i = 0; i < d[u]; i++){
			w = LG[u][i];
			if(dist[w] == INFTO){
				#ifdef DEBP
				cout << " " << w;
				#endif
				dist[w] = dist[u] + 1;
				pilha.push(w);
			}
		}
	}
	#ifdef DEBP
	cout << endl;
	#endif
	return dist[t];
}

int main(void){
	int i, u, w;
	while(cin >> N >> E >> I, N > 0){
		memset(d, 0, sizeof(d));
		for(i = 0; i < E; i++){
			cin >> u >> w;
			LG[u].push_back(w);
			d[u]++;
		}
		while(I--){
			cin >> u >> w;
			int resp = dfs(u, w);
			cout << "Distancia de " << u << " a " << w << ": ";
			if(resp != INFTO) cout << resp << endl;
			else cout << "infinito" << endl;
		}
		LG.clear();
	}
	return 0;
}
