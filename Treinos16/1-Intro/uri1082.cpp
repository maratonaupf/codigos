//#include<stdio.h>
#include<iostream>
//#include<string.h>
//#include<stdlib.h>
#include<algorithm>
//#include<stack>
#define MAX 123

using namespace std;

/* FUNCIONA SÓ COM qsort()
int cmp(const void *a, const void *b){
	return (*(char*) a - *(char*) b); 
}
*/
bool cmp(char a, char b){
	return a < b; 
}

int V, E;
int d[MAX];
int LG[MAX][MAX];
bool vis[MAX];

char store[MAX];
int tam;

//int pai[MAX];

void foiVisitado(int s){
	vis[s] = true; 
	store[tam++] = s+'a';
}

// recebe um vértice s e realiza a DFS
//int dfs(int s){
void dfs(int s){
	int u, w;
	//int ret = 0;
	//stack<int> p;
	int pilha[MAX], topo =-1;
	foiVisitado(s);
	//pai[s] = s;
	
	//pilha.push(s);
	pilha[++topo] = s;
	while(topo >= 0) {
		//u = pilha.top();
		//pilha.pop();
		u = pilha[topo--];
		
		for(int i = 0; i < d[u]; i++) {
			w = LG[u][i];
			if(vis[w] == false) {
				//pai[w] = u;
				foiVisitado(w);
				//pilha.push(w);
				pilha[++topo] = w;
			} 
			//else if (w != pai[u]) ret = 1;
		}
	}
	//return ret;
}

int main(void) {
	int u, v, tests, i, ncomp;
	char a, b;
	
	//scanf("%d", &tests);
	cin >> tests;
	for(int tc = 1; tc <= tests; tc++){
		//scanf("%d %d\n", &V, &E);
		cin >> V >> E;
		
		//memset(d, 0, sizeof(d));
		for(i = 0; i <= V; i++){
			d[i] = 0;
		}
		
		for(i = 0; i < E; i++){
			//scanf("%c %c\n", &a, &b);
			cin >> a >> b;
			u = a-'a'; 
			v = b-'a';
			
			LG[u][d[u]++] = v; 
			LG[v][d[v]++] = u;
		}
		
		ncomp = 0;
		//memset(vis, 0, sizeof(vis));
		for(i = 0; i <= V; i++){
			vis[i] = false;
		}
		
		//printf("Case #%d:\n", tc);
		cout << "Case #" << tc << ":" << endl;
		
		//RODA UMA DFS PARA CADA VÉRTICE NÃO VISITADO
		for(u = 0; u < V; u++) {
			if(vis[u] == false) {
				tam = 0;
				dfs(u);
				ncomp++;
				store[tam] = '\0';
				//qsort(store, tam, sizeof(char), cmp);
				//sort(store, store + tam, cmp);
				sort(&store[0], &store[tam], cmp);
				
				for(int k = 0; k < tam; k++){
					//printf("%c,", store[k]);
					cout << store[k] << ",";
				}
				//printf("\n");
				cout << endl;
			}
		}
		//printf("%d connected components\n\n", ncomp);
		cout << ncomp << " connected components" << endl << endl;
	}
	return 0;
}
