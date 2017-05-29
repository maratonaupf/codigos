/*
 * Leonardo Deliyannis Constantin
 * VI Maratona Mineira - Problema I: Invertendo Setas
 */

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
#define INFTO 112345678

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef map<int, int> mii;

int C, S;
vector<mii> LG;

int dijkstra(int s, int t){
	int u, w;
	priority_queue<ii, vector<ii>, greater<ii>> fila;
	vi dist(C+1, INFTO);
	dist[s] = 0;
	fila.push(ii(0, s));
	while(!fila.empty()){
		u = fila.top().second;
		fila.pop();
		for(auto it = LG[u].begin(); it != LG[u].end(); ++it){
			w = it->first;
			if(dist[u] + it->second < dist[w]){
				dist[w] = dist[u] + it->second;
				fila.push(ii(dist[w], w));
			}
		}
	}
	return dist[t];
}

int main(){
	int i, u, w;
	int A, B, X, Y;
	while(scanf("%d %d %d %d", &C, &S, &A, &B) != EOF){
		LG.assign(C+1, mii());
		for(i = 0; i < S; i++){
			scanf("%d %d", &u, &w);
			LG[u][w] = 0;
			if(!LG[w].count(u)) LG[w][u] = 1;
		}
		if((X = dijkstra(A, B)) >= INFTO || X == (Y = dijkstra(B, A))){
			printf("Bibibibika\n");
			continue;
		}
		printf("%s: %d\n", X < Y ? "Bibi" : "Bibika", X < Y ? X : Y);
		LG.clear();
	}
	return 0;
}
