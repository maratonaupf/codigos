#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stack>
#define MAX 123

using namespace std;

int cmp(const void *a, const void *b){
	return (*(char*) a - *(char*) b); 
}

int N, E;
int d[MAX];
int LG[MAX][MAX];
bool vis[MAX];
int pai[MAX];
char store[MAX];
int tam;

int dfs(int s) {
	int u, w, i, ret = 0;
	stack<int> p;
	vis[s] = true; store[tam++] = s+'a';
	pai[s] = s;
	
	p.push(s);
	while (!p.empty()) {
		u = p.top();
		p.pop();
		for (i = 0; i < d[u]; i++) {
			w = LG[u][i];
			if (!vis[w]) {
				pai[w] = u;
				vis[w] = true; store[tam++] = w+'a';
				p.push(w);
			} else if (w != pai[u]) ret = 1;
		}
	}
	return ret;
}

int main(void) {
	int u, v, tests, i, ncomp;
	char a, b;
	
	scanf("%d", &tests);
	for(int tc = 1; tc <= tests; tc++){
		scanf("%d %d\n", &N, &E);
		
		memset(d, 0, sizeof(d));
		for (i = 0; i < E; i++) {
			scanf("%c %c\n", &a, &b);
			u = a-'a'; v = b-'a';
			LG[u][d[u]++] = v; 
			LG[v][d[v]++] = u;
		}
		
		ncomp = 0;
		memset(vis, 0, sizeof(vis));
		printf("Case #%d:\n", tc);
		tam = 0;
		for (u = 0; u < N; u++) {
			if (!vis[u]) {
				dfs(u);
				ncomp++;
				store[tam] = '\0';
				qsort(store, tam, sizeof(char), cmp);
				for(int k = 0; k < tam; k++){
					printf("%c,", store[k]);
				}
				printf("\n");
				tam = 0;
			}
		}
		printf("%d connected components\n\n", ncomp);
	}
	return 0;
}
