#include<stdio.h>
#include<stdlib.h>
#define MAX 11

int revcmp(const void *a, const void *b){
	return *(int*)b - *(int*)a;
}

#define EPS 1e-9
int dblcmp(double a, double b){
	return a + EPS < b ? -1 : a > b + EPS ? 1 : 0;
}

int main(void){
	int N, V[MAX], i;
	int total;
	double p[MAX];
	while(scanf("%d", &N) != EOF){
		total = 0;
		for(i = 0; i < N; i++){
			scanf("%d", V+i);
			total += V[i];
		}
		qsort(V, N, sizeof(V[0]), &revcmp);
		for(i = 0; i < N; i++){
			p[i] = (double)(V[i] * 100) / (double)total;
		}
		int resp = (dblcmp(p[0], 45.0) != -1 || 
			(dblcmp(p[0], 40.0) != -1 && dblcmp(p[0]-p[1], 10.0) != -1)) ? 1 : 2;
		printf("%d\n", resp);
	}
	return 0;
}
