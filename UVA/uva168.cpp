/*
 * Leonardo Deliyannis Constantin
 * UVa 168 - Theseus and the Minotaur
 */

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 27
#define LEN 262

int N;
int LG[MAX][MAX];
int d[MAX];
int lit[MAX];

void execute(int m, int t, int k){
	memset(lit, 0, sizeof(lit));
	bool trapped = false;
	int v, cnt = 0;
	while(!trapped){
		trapped = true;
		for(int i = 0; trapped && i < d[m]; i++){
			v = LG[m][i];
			if(v == m || v == t || lit[v]) continue;
			t = m;
			m = v;
			cnt++;
			if(cnt % k == 0){
				printf("%c ", t+'A');
				lit[t] = true;
			}
			trapped = false;
		}
	}
	printf("/%c\n", m+'A');
}

int main(){
	int i, u, v, k;
	char s[LEN], m, t;
	while(scanf("%s", s), s[0] != '#'){
		scanf(" %c %c %d", &m, &t, &k);
		memset(d, 0, sizeof(d));
		N = 0;
		u = s[0] - 'A';
		for(i = 1; s[i] != '.'; i++){
			N = max(N, u);
			if(s[i] == ';'){
				u = s[++i] - 'A';
				continue;
			}
			if(s[i] == ':') continue;
			v = s[i] - 'A';
			LG[u][d[u]++] = v;
		}
		execute(m-'A', t-'A', k);
	}
	return 0;
}
