#include<stdio.h>

int main(void){
	int K, N, M, X, Y;
	while(scanf("%d", &K), K != 0){
		scanf("%d %d", &N, &M);
		while(K--){
			scanf("%d %d", &X, &Y);
			if(X == N || Y == M){
				printf("divisa\n");
			}else if(X > N){
				printf("%s\n", Y > M ? "NE" : "SE");
			}else if(X < N){
				printf("%s\n", Y > M ? "NO" : "SO");
			}
		}
	}
	return 0;
}
