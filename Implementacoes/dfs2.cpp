/* Descobre se um grafo não-dirigido é acíclico usando a DFS */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 123
//#define DEBP

int N, E;
char V[MAX][82];
int d[MAX];
int LG[MAX][MAX];
int vis[MAX];
int pai[MAX];

int comp(const void *a, const void *b) {
  return strcmp((char *)a, (char *)b);
}

int dfs(int s) {
  int pilha[MAX], topo, u, w, i, ret = 0;
  vis[s] = 1; pai[s] = s;
  pilha[topo = 0] = s;
  while (topo >= 0) {
    u = pilha[topo--];
    for (i = 0; i < d[u]; i++) {
      w = LG[u][i];
      if (!vis[w]) {
        pai[w] = u;
        vis[w] = 1;
        pilha[++topo] = w;
      } else if (w != pai[u]) ret = 1;
    }
  }
  return ret;
}

int main(void) {
  int i, u, v, temciclo = 0, ncomp = 0;
  char A[82], B[82];
  scanf("%d %d\n", &N, &E);
  for (i = 0; i < N; i++) {
    fgets(V[i], 82, stdin);
  }
  qsort(V, N, sizeof(V[0]), &comp);
  memset(d, 0, sizeof(d));
  for (i = 0; i < E; i++) {
    fgets(A, 82, stdin); fgets(B, 82, stdin);
    u = ((size_t)bsearch(&A, V, N, sizeof(V[0]), &comp) - (size_t)V) / sizeof(V[0]);
    v = ((size_t)bsearch(&B, V, N, sizeof(V[0]), &comp) - (size_t)V) / sizeof(V[0]);
    LG[u][d[u]++] = v; LG[v][d[v]++] = u;
  }
#ifdef DEBP
  for (u = 0; u < N; u++) {
    printf("%s", V[u]);
    for (v = 0; v < d[u]; v++) {
      printf(">%s", V[LG[u][v]]);
    }
  } 
#endif
  memset(vis, 0, sizeof(vis));
  for (u = 0; u < N; u++) {
    if (!vis[u]) {
      temciclo |= dfs(u);
      ncomp++;
    }
  }
  printf("%s\n", temciclo ? "Ciclico" : "Aciclico");
  printf("Num. componentes: %d\n", ncomp);
  return 0;
}




