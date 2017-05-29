/*
 * Leonardo Deliyannis Constantin
 * URI 1524 - Fila do Bandejão
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 1123
#define indices_push(dist, idx) do{ indices[i].first = dist; indices[i].second = idx; }while(0)

typedef struct _pair{
	int first, second;
} ii;

int distCmp(const void *p1, const void *p2){
	ii a = *(ii*)p1;
	ii b = *(ii*)p2;
	return b.first - a.first;
}

int idxCmp(const void *p1, const void *p2){
	ii a = *(ii*)p1;
	ii b = *(ii*)p2;
	return a.second - b.second;
}

int main(void){
	ii indices[MAX];
	int N, K, i;
	int pos[MAX];
	int soma, anterior, atual;
	while(scanf("%d %d", &N, &K) != EOF){
		pos[0] = i = 0;
		indices_push(0, 0);
		for(i = 1; i < N; i++){
			scanf("%d", &pos[i]);
			indices_push(pos[i] - pos[i-1], i);
		}
		qsort(indices, N, sizeof(indices[0]), &distCmp);
		qsort(indices, --K, sizeof(indices[0]), &idxCmp);
		soma = 0;
		atual = 0;
		for(i = 0; i < K; i++){
			anterior = atual;
			atual = indices[i].second;
			soma += pos[atual-1] - pos[anterior];
		}
		soma += pos[N-1] - pos[atual];
		printf("%d\n", soma);
	}
	return 0;
}

