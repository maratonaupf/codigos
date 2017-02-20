#include<stdio.h>
#include<string.h>

#define max(x, y) ((x) > (y) ? (x) : (y))
#define MAX 123

int W, N, i, v[MAX], w[MAX];
int S[MAX][MAX];

int PD() {
	int i, m;
	for (m = 0; m <= W; m++) // i = 1
		S[1][m] = w[1] <= m ? v[1] : 0;
	for (i = 1; i <= N; i++) // m = 0
		S[i][0] = 0;
	for (i = 2; i <= N; i++)
		for (m = 1; m <= W; m++) {
			if (w[i] <= m)
				S[i][m] = max(S[i - 1][m], S[i - 1][m - w[i]] + v[i]);
			else S[i][m] = S[i - 1][m];
		}
	return S[N][W];
}

int main(void) {
	scanf("%d %d", &W, &N);
	for (i = 1; i <= N; i++) scanf("%d", &v[i]);
	for (i = 1; i <= N; i++) scanf("%d", &w[i]);
	memset(S, -1, sizeof(S));
	printf("%d\n", PD());
	return 0;
}

