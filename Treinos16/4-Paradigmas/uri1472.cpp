#include<stdio.h>
#include<stdlib.h>
#define MAX 112345

int cmp_int(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}

int main(void){
	int N, i, v[MAX], p[MAX];
	int key, key2, acum, triangles;
	while(scanf("%d", &N) != EOF){
		acum = 0;
		for(i = 0; i < N; i++){
			scanf("%d", v+i);
			acum += v[i];
			p[i] = (i > 0) ? p[i-1] + v[i] : v[i];
		}
		acum /= 3;
		triangles = 0;
		for(i = 0; i < N; i++){
			key = p[i] + acum;
			key2 = p[i] + acum * 2;
			if(bsearch(&key, p, N, sizeof(p[0]), cmp_int) && 
				bsearch(&key2, p, N, sizeof(p[0]), cmp_int))
					triangles++;
		}
		printf("%d\n", triangles);
	}
	return 0;
}
