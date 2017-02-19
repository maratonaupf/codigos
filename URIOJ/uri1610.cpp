#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 11234 /* 10^4 */
//#define DEBP

int N, M, /* Quant. de vértices e arestas, respectivamente */
	d[MAX], /* Vizinhança dos vértices */
	LG[MAX][MAX], /* Lista de adjacência */
	vis[MAX], /* Indica se o vértice já foi visitado */
	rec[MAX], /* Pilha de recursão */
	pai[MAX]; /* Pai de cada vértice */
	//existe[MAX]; /* Gambiarra para poder criar uma superorigem */
	
int comp(const void * a, const void * b){
	return ( *(int*)a - *(int*)b );}

int dfsr(int u){
	int w, i;
	if(!vis[u]){
		vis[u] = rec[u] = 1;
		for(i = 0; i < d[u]; i++){
			w = LG[u][i];
			if(!vis[w] && dfsr(w))
				return 1;
			else if(rec[w])
				return 1;
		}
	}
	rec[u] = 0;
	return 0;
}

int dfs(int s){
	int u, w, i, pilha[MAX], topo, ret = 0;
	pai[s] = s;
	pilha[topo = 0]= s;
	while(topo >= 0){
		u = pilha[topo--];
		for(i = 0; i < d[u]; i++){
			w = LG[u][i];
			if(!vis[w]){
				vis[w] = 1;
				pai[w] = u;
				pilha[++topo] = w;
			}else if(w != pai[u]) ret = 1;
		}
	}
	return ret;
}

int ehciclico(){
	memset(vis, 0, sizeof(vis)); /* Nenhum vértice foi visitado */
	memset(rec, 0, sizeof(rec)); /* Nenhum vértice foi visitado */
	
	for(int u = 1; u <= N; u++)
		if(dfsr(u)) return 1;	
	return 0;
}

int main(void) {
	int T, i, A, B;
	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &N, &M);
		
		memset(d, 0, sizeof(d));
		
		for(i = 0; i < M; i++) {
			scanf("%d %d", &A, &B);
			LG[A][d[A]++] = B;
		}
		
		for(A = 1; A <= N; A++)
			qsort(LG[A], d[A], sizeof(int), &comp);
		memset(vis, 0, sizeof(vis));
		int temciclo = 0;
		for(A = 1; A <= N; A++){
			if(!vis[A]) temciclo |= dfs(A);
		}
		
		printf("%s\n", temciclo ? "SIM" : "NAO");
	}
	return 0;
}




