/*
 * Leonardo Deliyannis Constantin
 * URI 2168 - Crepúsculo em Portland
 */

#include <stdio.h>
#define MAX 112

int grid[MAX][MAX];

inline bool safe(int i, int j){
	return (grid[i][j] + grid[i-1][j] 
		+ grid[i][j-1] + grid[i-1][j-1]) >= 2;
}

int main(){
	int N, i, j;
	while(scanf("%d", &N) != EOF){
		for(i = 0; i <= N; i++){
			for(j = 0; j <= N; j++){
				scanf("%d", &grid[i][j]);
				if(i > 0 && j > 0){
					putchar(safe(i, j) ? 'S' : 'U');
				}
			}
			if(i > 0) printf("\n");
		}
	}
	return 0;
}
