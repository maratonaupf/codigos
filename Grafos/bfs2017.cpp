/*
 * Leonardo Deliyannis Constantin
 * BFS simples: computa a distância de S a T
 */

#include <iostream>
#include <queue>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
#define INFTO 112345678

int V, E;
vector<string> cidades;
map<string, vector<string> > adjList;

int bfs(string s, string t){
	string u, w;
	int i;
	map<string, int> dist;
	queue<string> fila;
	for(i = 0; i < V; i++){
		dist[cidades[i]] = INFTO;
	}
	dist[s] = 0;
	fila.push(s);
	while(!fila.empty()){
		u = fila.front();
		fila.pop();
		int tam = (int) adjList[u].size();
		for(i = 0; i < tam; i++){
			w = adjList[u][i];
			if(dist[w] == INFTO){
				dist[w] = dist[u] + 1;
				fila.push(w);
			}
		}
	}
	return dist[t];
}

int main(){
	string s1, s2;
	int Q, resp, i;
	while(cin >> V >> E){
		for(i = 0; i < V; i++){
			cin >> s1;
			cidades.push_back(s1);
		}
		for(i = 0; i < E; i++){
			cin >> s1 >> s2;
			adjList[s1].push_back(s2);
			adjList[s2].push_back(s1);
		}
		cin >> Q;
		while(Q--){
			cin >> s1 >> s2;
			cout << "Estradas entre " << s1 << " e " << s2 << ": ";
			resp = bfs(s1, s2);
			(resp != INFTO) ? cout << resp : cout << "impossivel";
			cout << endl;
		}
	}
	return 0;
}
