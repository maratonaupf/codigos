/*
 * Leonardo Deliyannis Constantin
 * Header
 */

#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
#define MAX 112
#define INFTO 112345678

typedef pair<int, int> ii;

int N, E; // Vertices, arestas
int adjList[MAX][MAX]; // Lista de adjacência
int d[MAX]; // Quantidade de vizinhos
int peso[MAX][MAX];
int dist[MAX];

void dijkstra(int s){
	int u, w, i;
	priority_queue<ii, vector<ii>, greater<ii>> fila;
	for(u = 0; u <= N; u++){
		dist[u] = INFTO;
	}
	dist[s] = 0;
	fila.push(ii(0, s));
	while(!fila.empty()){
		u = fila.top().second;
		fila.pop();
		for(i = 0; i < d[u]; i++){
			w = adjList[u][i];
			if(dist[u] + peso[u][w] < dist[w]){
				dist[w] = dist[u] + peso[u][w];
				fila.push(ii(dist[w], w));
			}
		}
	}
}

int main(){
	int i, u, w, p;
	char A, B;
	while(scanf("%d %d\n", &N, &E) != EOF && N != 0 && E != 0){
		memset(d, 0, sizeof(d));
		for(i = 0; i < E; i++){
			scanf("%c %c %d\n", &A, &B, &p);
			u = A - 'A' + 1;
			w = B - 'A' + 1;
			// insere w na lista de vizinhos de u - e vice-versa
			adjList[u][d[u]++] = w;
			adjList[w][d[w]++] = u;
			peso[u][w] = peso[w][u] = p;
		}
		printf("### ");
		for(u = 1; u <= N; u++){
			printf(" %3c", (char)u+'A'-1);
		}
		printf("\n");
		for(u = 1; u <= N; u++){
			dijkstra(u);
			printf("%3c:", (char)u+'A'-1);
			for(w = 1; w <= N; w++)
				printf(" %3d", dist[w]);
			printf("\n");
		}
	}
	return 0;
}
