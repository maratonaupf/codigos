#include<stdio.h>
#define MAX 112345

int buscaBin(int v[], int N){
	int inic, fim, meio;
	if(N == 1) return 1;
	inic = 0;
	fim = N-1;
	while(meio = inic + (fim-inic)/2, inic <= fim){
		if(v[meio] == v[N-1] - v[meio]) return meio + 1;
		if(v[meio]  < v[N-1] - v[meio]) inic = meio + 1;
		if(v[meio]  > v[N-1] - v[meio]) fim  = meio - 1;
	}
	return -1;
}

int main(void){
	int N, i, atual, v[MAX];
	while(scanf("%d", &N) != EOF){
		scanf("%d", &v[0]);
		for(i = 1; i < N; i++){
			scanf("%d", &atual);
			v[i] = v[i-1] + atual;
		}
		printf("%d\n", buscaBin(v, N));
	}
	return 0;
}
