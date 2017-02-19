#include<stdio.h>
#include<string.h>
#define MAX 212

int main(void){
	int N, M, C, x;
	int h[MAX][MAX];
	int d[MAX];
	scanf("%d", &N);
	while(N--){
		scanf("%d %d", &M, &C);
		memset(d, 0, sizeof(d));
		while(C--){
			scanf("%d", &x);
			h[x%M][d[x%M]++] = x;
		}
		for(int i = 0; i < M; i++){
			printf("%d -> ", i);
			for(int j = 0; j < d[i]; j++){
				printf("%d -> ", h[i][j]);
			}
			printf("\\\n");
		}
		if(N) printf("\n");
	}
	return 0;
}
