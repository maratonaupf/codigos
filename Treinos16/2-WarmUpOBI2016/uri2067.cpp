#include<stdio.h>
#define MAX 212
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int main(void){
	int N, M, Q, i, j, maior;
	int grid[MAX][MAX];
	int dp[MAX][MAX];
	while(scanf("%d %d", &N, &M) != EOF){
		maior = 0;
		for(i = 1; i <= N; i++){
			for(j = 1; j <= M; j++){
				scanf("%d", grid[i]+j);
				dp[i][j] = (grid[i][j] == 0) ? 0 :
					min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
				maior = max(maior, dp[i][j]);
			}
		}
		scanf("%d", &Q);
		while(Q--){
			scanf("%d", &i);
			puts(i <= maior ? "yes" : "no");
		}
	}
	return 0;
}
