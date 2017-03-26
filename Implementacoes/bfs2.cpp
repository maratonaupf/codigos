/* Constrói o caminho de s a t a partir da BFS */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 123
#define INFTO 112345678
//#define DEBP

int N, E;
char V[MAX][82];
int d[MAX];
int LG[MAX][MAX];
int pai[MAX];

int comp(const void *a, const void *b) {
  return strcmp((char *)a, (char *)b);
}

void bfs(int s, int t) {
  int fila[MAX], dist[MAX], inic, fim, u, w, i;
  for (u = 0; u < N; u++) dist[u] = INFTO;
  dist[s] = 0; pai[s] = s;
  fila[inic = fim = 0] = s;
  while (inic <= fim) {
    u = fila[inic++];
    for (i = 0; i < d[u]; i++) {
      w = LG[u][i];
      if (dist[w] == INFTO) {
        dist[w] = dist[u] + 1;
        pai[w] = u;
        fila[++fim] = w;
      }
      if (w == t) fim = inic - 1;
    }
  }
}

int main(void) {
  int i, u, v, s, t, P[MAX], tP;
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
  bfs(s, t);
  P[tP = 0] = t;
  for (u = t; u != s; u = pai[u]) P[++tP] = pai[u];
  for (i = tP; i >= 0; i--) printf("%s", V[P[i]]);
  return 0;
}




