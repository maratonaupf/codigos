#include<stdio.h>
#include<stdlib.h>  // qsort()
#include<math.h>    // fabs()
#define MAX 112
#define EPS 1e-9
#include<algorithm> // max()
using namespace std;

int cmp(const void *p1, const void *p2){
	double a = *(double*)p1;
	double b = *(double*)p2;
	return (fabs(a-b) > EPS) ? (a < b) ? -1 : 1 : 0;
}

int main(void){
	int f, r, fg[MAX], rg[MAX], i, j, tam;
	double d[MAX], maxSpread;
	while(scanf("%d", &f), f != 0){
		scanf("%d", &r);
		for(i = 0; i < f; i++) scanf("%d", fg+i);
		tam = 0;
		for(i = 0; i < r; i++){
			scanf("%d", rg+i);
			for(j = 0; j < f; j++)
				d[tam++] = (double)rg[i] / (double)fg[j];
		}
		maxSpread = 0.0;
		qsort(d, tam, sizeof(d[0]), &cmp);
		for(i = 1; i < tam; i++){
			if((d[i] / d[i-1]) > maxSpread+EPS)
				maxSpread = d[i] / d[i-1];
		}
		printf("%.2lf\n", maxSpread);
	}
	return 0;
}
