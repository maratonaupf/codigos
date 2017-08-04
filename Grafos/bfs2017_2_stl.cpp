#include <iostream>
#include <string.h>
#include <map>
#include <vector>
#include <queue>
#define MAX 112
#define INFTO 112345678
using namespace std;

int N, E; // vértices e arestas
map<char, vector<char>> LG; // lista de adjacência

void mostraLista(){
	for(auto it = LG.begin(); it != LG.end(); ++it){
		cout << "Vertice " << it->first << ":";
		for(char c : it->second){
			cout << " " << c;
		}
		cout << "\n";
	}
}

int bfs(char s, char t){
	map<char, int> dist;
	for(auto it = LG.begin(); it != LG.end(); ++it){
		dist[it->first] = INFTO;
	}
	dist[s] = 0;
	queue<char> fila;
	fila.push(s);
	while(!fila.empty()){
		char u = fila.front();
		fila.pop();
		for(char w : LG[u]){
			if(dist[w] == INFTO){
				dist[w] = dist[u] + 1;
				fila.push(w);
			}
			if(w == t){
				while(!fila.empty()){
					fila.pop();
				}
			}
		}
	}
	return dist[t];
}

int main(){
	char a, b;
	int Q;
	while(cin >> N >> E, N != 0){
		for(int i = 1; i <= E; i++){
			cin >> a >> b;
			LG[a].push_back(b);
			LG[b].push_back(a);
		}
		mostraLista();
		cin >> Q;
		while(Q--){
			cin >> a >> b;
			cout << "Dist. entre ";
			cout << a << " e " << b;
			cout << ": " << bfs(a, b) << "\n";
		}
	}
	return 0;
}
