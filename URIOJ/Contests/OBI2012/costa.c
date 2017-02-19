#include<stdio.h>
#define MAX 1123
#define isValid(_a, _b) (0 <= (_a) && (_a) < M && 0 <= (_b) && (_b) < N)

int M, N;
char grid[MAX][MAX];
const int di[] = { -1, 0, 0, 1 };
const int dj[] = { 0, -1, 1, 0 };

int _isCoastal(int i, int j){
	int k, i2, j2, count;
	if(grid[i][j] == '.') return 0;
	count = 0;
	for(k = 0; k < 4; k++){
		i2 = i+di[k];
		j2 = j+dj[k];
		if(!isValid(i2, j2) || grid[i2][j2] == '.') count++;
	}
	return (count > 0);
}

int coastSize(){
	int i, j, ret;
	ret = 0;
	for(i = 0; i < M; i++){
		for(j = 0; j < N; j++){
			if(_isCoastal(i, j)){
				ret++;
			}
		}
	}
	return ret;
}

int main(void){
	int i;
	while(scanf("%d %d\n", &M, &N) != EOF){
		for(i = 0; i < M; i++){
			fgets(grid[i], MAX, stdin);
			grid[i][N] = '\0';
		}
		printf("%d\n", coastSize(grid, M, N));
	}
	return 0;
}
