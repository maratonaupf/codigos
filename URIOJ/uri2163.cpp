/*
 * Leonardo Deliyannis Constantin
 * URI 2163 - O Despertar da Força
 */

#include <stdio.h>
#define MAX 1123

int N, M;
int grid[MAX][MAX];
int di[] = { -1, -1, -1,  0,  0,  1,  1,  1 };
int dj[] = { -1,  0,  1, -1,  1, -1,  0,  1 };

bool isValid(int i, int j){
	return 0 < i && i <= N && 0 < j && j <= M;
}

bool isLightSaber(int i, int j){
	int k, i2, j2;
	if(!isValid(i, j) || grid[i][j] != 42) 
		return false;
	for(k = 0; k < 8; k++){
		i2 = i+di[k], j2 = j+dj[k];
		if(!isValid(i2, j2) || grid[i2][j2] != 7)
			return false;
	}
	return true;
}

int main(){
	int i, j, x, y;
	while(scanf("%d %d", &N, &M) != EOF){
		x = y = 0;
		for(i = 1; i <= N; i++){
			for(j = 1; j <= M; j++){
				scanf("%d", &grid[i][j]);
				if(isLightSaber(i-1, j-1)){
					x = i-1, y = j-1;
				}
			}
		}
		printf("%d %d\n", x, y);
	}
	return 0;
}
