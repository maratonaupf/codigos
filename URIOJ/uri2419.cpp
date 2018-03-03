/*
 * Leonardo Deliyannis Constantin
 * URI 2419 - Costa 
*/

#include <stdio.h>
#define MAX 11234

int N, M;
char grid[MAX][MAX];
int di[] = { -1,  0,  0,  1 };
int dj[] = {  0, -1,  1,  0 };

inline bool isValid(int i, int j){
	return 0 <= i && i < N && 0 <= j && j < M;
}

bool isCoast(int i, int j){
	return (!isValid(i, j) || grid[i][j] == '.');
}

int main(){
	int i, j, k, i2, j2;
	int ans;
	while(scanf("%d %d ", &N, &M) != EOF){
		for(i = 0; i < N; i++){
			fgets(grid[i], MAX, stdin);
			grid[i][M] = 0;
		}
		ans = 0;
		for(i = 0; i < N; i++){
			for(j = 0; j < M; j++){
				if(grid[i][j] == '.')
					continue;
				for(k = 0; k < 4; k++){
					i2 = i+di[k];
					j2 = j+dj[k];
					if(isCoast(i2, j2)){
						ans++;
						break;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
