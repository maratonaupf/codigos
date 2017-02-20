#include<stdio.h>
#include<string.h>

#define max(x, y) ((x) > (y) ? (x) : (y))
#define MAX 123

int W, N, i, v[MAX], w[MAX];
int S[MAX][MAX];

int PD(int i, int m) {
  if (S[i][m] != -1) return S[i][m];
  if (i == 1 && w[i] <= m) return S[i][m] = v[i];
  if (i == 1) return S[i][m] = 0;
  if (m == 0) return S[i][m] = 0;
  if (w[i] > m) return S[i][m] = PD(i - 1, m);
  return S[i][m] = max(PD(i - 1, m), PD(i - 1, m - w[i]) + v[i]);
}

int main(void) {
  scanf("%d %d", &W, &N);
  for (i = 1; i <= N; i++) scanf("%d", &v[i]);
  for (i = 1; i <= N; i++) scanf("%d", &w[i]);
  memset(S, -1, sizeof(S));
  printf("%d\n", PD(N, W));
  return 0;
}

