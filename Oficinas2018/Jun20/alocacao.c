#include <stdio.h>
#include <stdlib.h>

int compara(const void *a, const void *b){
	/*
	int *p1 = (int*) a;
	int *p2 = (int*) b;
	return *p1 - *p2;
	*/
	return *(int*)a - *(int*)b;
}

int main(){
	int N, i;
	int *p;
	scanf("%d", &N);
	p = (int*) malloc(N * sizeof(int));
	for(i = 0; i < N; i++){
		scanf("%d", &p[i]);
	}
	qsort(p, N, sizeof(int), &compara);
	for(i = 0; i < N; i++){
		printf("%d%c", p[i], (i < N-1) ? ' ' : '\n');
	}
	free(p);
	return 0;
}
