/*
 * Leonardo Deliyannis Constantin 
 * URI 2552 - PãodeQuejoSweeper
*/

#include <stdio.h>
#include <string.h>
#define MAX 112

int N, M;
const int di[] = { -1, 1,  0, 0 };
const int dj[] = {  0, 0, -1, 1 };
char grid[MAX][MAX];

inline bool isValid(int i, int j){
	return 0 <= i && i < N && 0 <= j && j < M;
}

int main(){
	int i, j, k, i2, j2, temPao;
	while(scanf(" %d %d", &N, &M) != EOF){
		memset(grid, '0', sizeof(grid));
		for(i = 0; i < N; i++){
			grid[i][M] = 0;
			for(j = 0; j < M; j++){
				scanf(" %d", &temPao);
				if(temPao)
					grid[i][j] = '9';
			}
		}
		for(i = 0; i < N; i++){
			for(j = 0; j < M; j++){
				if(grid[i][j] == '9')
					continue;
				for(k = 0; k < 4; k++){
					i2 = i+di[k];
					j2 = j+dj[k];
					if(isValid(i2, j2) && grid[i2][j2] == '9')
						grid[i][j]++;
				}
			}
			printf("%s\n", grid[i]);
		}
	}
	return 0;
}
