#include<stdio.h>
#include<stdlib.h> // abs()
#define MAX 1123

int main(void){
	int N, M, T = 0;
	int v[MAX], q, i, j, sum;
	while(scanf("%d", &N), N != 0){
		T++;
		for(i = 0; i < N; i++){
			scanf("%d", v+i);
		}
		scanf("%d", &M);
		printf("Case %d:\n", T);
		while(M--){
			scanf("%d", &q);
			sum = v[0] + v[1];
			for(i = 0; i < N; i++){
				for(j = 0; j < N; j++){
					if(i == j) continue;
					if(abs((v[i] + v[j]) - q) < abs(sum - q))
						sum = v[i] + v[j];
				}
			}
			printf("Closest sum to %d is %d.\n", q, sum);
		}
	}
	return 0;
}
