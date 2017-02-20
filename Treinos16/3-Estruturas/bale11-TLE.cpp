#include<stdio.h>
#define MAX 112345

int main(void){
	int N, i, j;
	int v[MAX];
	int pares;
	while(scanf("%d", &N) != EOF){
		for(i = 0; i < N; i++){
			scanf("%d", v+i);
		}
		pares = 0;
		for(i = 1; i < N; i++){
			for(j = 0; j < i; j++){
				if(v[j] > v[i])
					pares++;
			}
		}
		printf("%d\n", pares);
	}
	return 0;
}
