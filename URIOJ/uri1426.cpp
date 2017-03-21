#include<stdio.h>

int main(void){
	int N, i, j;
	int mat[9][9];
	// cin >> N;
	scanf("%d", &N);
	// while(N = N - 1, N != 0){
	while(N--){
		for(i = 0; i < 9; i += 2){
			for(j = 0; j <= i; j += 2){
				scanf("%d", &mat[i][j]);
				if(i>=2 && j>=2){
					mat[i][j-1] = (mat[i-2][j-2] - (mat[i][j-2] + mat[i][j])) / 2;
					mat[i-1][j-2] = mat[i][j-2] + mat[i][j-1];
					mat[i-1][j-1] = mat[i][j-1] + mat[i][j];
				}
			}
		}
		for(i = 0; i < 9; i++){
			for(j = 0; j <= i; j++){
				printf("%d%c", mat[i][j], (j < i) ? ' ' : '\n');
			}
		}
	}
	return 0;
}
