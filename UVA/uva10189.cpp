#include<stdio.h>
#define MAX 112

int N, M;
char grid[MAX][MAX];
int di[] = { -1, -1, -1,  0, 0,  1, 1, 1 };
int dj[] = { -1,  0,  1, -1, 1, -1, 0, 1 };

int main(void){
	int i, j, k, i2, j2, bombs, fieldNo = 0;
	while(scanf("%d %d\n", &N, &M), N != 0){
		for(i = 0; i < N; i++){
			fgets(grid[i], MAX, stdin);
		}
		for(i = 0; i < N; i++){
			for(j = 0; j < M; j++){
				if(grid[i][j] != '*'){
					bombs = 0;
					for(k = 0; k < 8; k++){
						i2 = i+di[k]; 
						j2 = j+dj[k];
						if(0 <= i2 && i2 < N && 0 <= j2 && j2 < M &&
							grid[i2][j2] == '*') bombs++;
					}
					grid[i][j] = '0' + bombs;
				}
			}
		}
		if(fieldNo > 0) printf("\n");
		printf("Field #%d:\n", ++fieldNo);
		for(i = 0; i < N; i++){
			printf("%s", grid[i]);
		}
	}
	return 0;
}
