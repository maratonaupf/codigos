#include<stdio.h>
#define MAX 112

int R, C;
int di[] = {-1,  0, 0, 1};
int dj[] = { 0, -1, 1, 0};

bool loseTo(char c1, char c2){
	return (c1 == 'R' && c2 == 'P')
		|| (c1 == 'P' && c2 == 'S')
		|| (c1 == 'S' && c2 == 'R');
}

char replacer(char c){
	return c == 'R' ? 'P' : c == 'P' ? 'S' : 'R';
}

void simulate(char dest[MAX][MAX], char src[MAX][MAX]){
	int i, j, k, i2, j2;
	bool taken;
	for(i = 0; i < R; i++){
		for(j = 0; j < C; j++){
			taken = false;
			for(k = 0; k < 4 && !taken; k++){
				i2 = i+di[k];
				j2 = j+dj[k];
				if(0 <= i2 && i2 < R && 0 <= j2 && j2 < C &&
					loseTo(src[i][j], src[i2][j2])){
					taken = true;
				}
			}
			dest[i][j] = taken ? replacer(src[i][j]) : src[i][j];
		}
	}
}

int main(void){
	int T, N, i;
	char grid[MAX][MAX], aux[MAX][MAX];
	bool orig, first = true;
	scanf("%d", &T);
	while(T--){
		if(first) first = false;
		else printf("\n");
		scanf("%d %d %d\n", &R, &C, &N);
		for(i = 0; i < R; i++){
			fgets(grid[i], MAX, stdin);
			grid[i][C] = aux[i][C] = '\0';
		}
		orig = true;
		while(N--){
			if(orig) simulate(aux, grid);
			else simulate(grid, aux);
			orig = !orig;
		}
		for(i = 0; i < R; i++){
			printf("%s\n", orig ? grid[i] : aux[i]);
		}
	}
	return 0;
}
