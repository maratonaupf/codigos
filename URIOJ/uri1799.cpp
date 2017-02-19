#include<iostream>
#include<map>
#include<queue>
#include<vector>
#define INFTO 1123456789

using namespace std;

int N, E;
typedef map<string,vector<string>> grafo;
typedef map<string,int> msi;
grafo LG;

int bfs(string s, string t) { 
	msi dist;
	queue<string> fila;
	string u, w;
	
	for (grafo::iterator it = LG.begin(); it != LG.end(); ++it){ 
		dist[it->first] = INFTO;
	}
	dist[s] = 0;
 
	fila.push(s);
	while (!fila.empty()) {
		u = fila.front();
		fila.pop();
		for (size_t i = 0; i < LG[u].size(); i++) {
			w = LG[u][i];
			if (dist[w] == INFTO) {
				dist[w] = dist[u] + 1;
				fila.push(w);
			}
		}
	}
	return dist[t];
}

int main(void){
	string u, v;
	int resp;
	while(cin >> N >> E){
		for(int i = 0; i < E; i++){
			cin >> u >> v;
			LG[u].push_back(v);
			LG[v].push_back(u);
		}
		
		resp = bfs("Entrada", "*");
		resp += bfs("*", "Saida");
		cout << resp << endl;
		LG.clear();
	}
	
	return 0;
}
