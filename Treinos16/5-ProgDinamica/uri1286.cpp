#include<stdio.h>
#include<string.h>
#include<algorithm>
#define MAX 112

int q[MAX], t[MAX];
int m[MAX][MAX];

int PD(int N, int W){
	int tempo, soma, i, j;
	memset(m, 0, sizeof(m));
	for(i = 1; i <= N; i++){
		for(j = 1; j <= W; j++){
			tempo = m[i-1][j];
			if(q[i] <= j){
				soma = m[i-1][j-q[i]] + t[i];
				if(tempo < soma) tempo = soma;
			}
			m[i][j] = tempo;
		}
	}
	return m[N][W];
}

int main(void){
	int N, P;
	while(scanf("%d", &N), N){
		scanf("%d", &P);
		for(int i = 1; i <= N; i++) scanf("%d %d", t+i, q+i);
		printf("%d min.\n", PD(N, P));
	}
	return 0;
}
