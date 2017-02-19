#include<stdio.h>
#include<string.h>
 
#define INFTO 112345678
#define MAX 40034 // LEMBRE-SE DE SETAR O MAX PARA CADA PROBLEMA
 
int N, E;
int LG[MAX][MAX];
int d[MAX];
int AG[MAX][MAX];
int dist[MAX];

/* Código de heap => copiar e colar sem entender */
int H[MAX];
int emH[MAX];
int tamH;
#define PAI(x) ((x) >> 1)
#define ESQ(x) ((x) << 1)
#define DIR(x) (ESQ(x) + 1)
void troque(int i, int j) {
	int tmp;
	tmp = H[i];
	H[i] = H[j]; H[j] = tmp; emH[H[i]] = i; emH[H[j]] = j;
}
void heapify(int i) {
	int menor = i;
	if (ESQ(i) <= tamH && dist[H[ESQ(i)]] < dist[H[i]])
		menor = ESQ(i);
	if (DIR(i) <= tamH && dist[H[DIR(i)]] < dist[H[menor]])
		menor = DIR(i);
	if (menor == i) return;
	troque(i, menor);
	heapify(menor);
}
int extraia_min(void) {
	troque(1, tamH);
	emH[H[tamH--]] = 0;
	heapify(1);
	return H[tamH + 1];
}
void rebaixe(int i) {
	for (; i > 1 && dist[H[i]] < dist[H[PAI(i)]]; i = PAI(i))
	troque(i, PAI(i));
}
/* Fim do código de heap */

void dijkstra(int s) {
	int u, w, i;
	for (u = 1; u <= N; u++) {
		dist[u] = INFTO; H[u] = u; emH[u] = u;
	}
	dist[s] = 0; troque(1, emH[s]); tamH = N;
	while (tamH > 0) {
		u = extraia_min();
		for (i = 0; i < d[u]; i++) {
			w = LG[u][i];
			if (emH[w] && dist[w] > dist[u] + AG[u][w]) {
				dist[w] = dist[u] + AG[u][w];
				rebaixe(emH[w]);			
			}
		}
	}
}
 
int main(void) {
	int i, j, u, v, peso;
	while(scanf("%d %d", &N, &E), N){
		memset(d, 0, sizeof(d));
		for (i=0; i<=N; i++)
			for (j=0; j<=N; j++) AG[i][j] = INFTO;
		for (i=1; i <= E; i++) {
			scanf("%d %d %d", &u, &v, &peso);
			u+=1; v+=1;
			LG[u][d[u]++] = v;	LG[v][d[v]++] = u; 
			AG[u][v] = AG[v][u] = peso;
		}
		
		printf("\n");
	}
	return 0;
}
