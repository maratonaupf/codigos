/* DFS simples: apenas descobre se tem caminho de s a t */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 123
//#define DEBP

int N, E;
char V[MAX][82];
int d[MAX];
int LG[MAX][MAX];

int comp(const void *a, const void *b) {
  return strcmp((char *)a, (char *)b);
}

int dfs(int s, int t) {
  int pilha[MAX], vis[MAX], topo, u, w, i;
  memset(vis, 0, sizeof(vis)); vis[s] = 1;
  pilha[topo = 0] = s;
  while (topo >= 0) {
    u = pilha[topo--];
    for (i = 0; i < d[u]; i++) {
      w = LG[u][i];
      if (w == t) return 1;
      if (!vis[w]) {
        vis[w] = 1;
        pilha[++topo] = w;
      }
    }
  }
  return 0;
}

int main(void) {
  int i, u, v, s, t;
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
  fgets(A, 82, stdin); fgets(B, 82, stdin);
  s = ((size_t)bsearch(&A, V, N, sizeof(V[0]), &comp) - (size_t)V) / sizeof(V[0]);
  t = ((size_t)bsearch(&B, V, N, sizeof(V[0]), &comp) - (size_t)V) / sizeof(V[0]);
  printf("%s\n", dfs(s, t) ? "Sim" : "Nao");
  return 0;
}




