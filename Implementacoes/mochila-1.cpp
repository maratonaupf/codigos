#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int W, N, i;
vector<int> v, w;
vector<vector<int> > S;

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
	v.reserve(N+1);
	w.reserve(N+1);
	for (i = 1; i <= N; i++) scanf("%d", &v[i]);
	for (i = 1; i <= N; i++) scanf("%d", &w[i]);
	S.assign(N+1, vector<int>(N+1, -1));
	printf("%d\n", PD(N, W));
	return 0;
}

