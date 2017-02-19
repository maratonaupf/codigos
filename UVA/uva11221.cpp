#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define MAX 112
#define TAM 10002
#define EPS 1e-9

char grid[MAX][MAX];

int lettersIn(char *s){
	int i, count = 0;
	for(i = 0; s[i]; i++){
		if(isalpha(s[i])) count++;
	}
	return count;
}

int stringToGrid(char *s){
	double _M;
	int i, j, k, M;
	_M = sqrt(lettersIn(s));
	M = _M;
	if(fabs(_M - (double)M) > EPS) return 0;
	k = 0;
	for(i = 0; i < M; i++){
		for(j = 0; j < M; j++){
			while(!isalpha(s[k])) k++;
			grid[i][j] = s[k++];
		}
		grid[i][M] = 0;
	}
	return M;
}

int isMSP(char *s){
	int i, j, M;
	M = stringToGrid(s);
	if(M == 0) return 0;
	for(i = 0; i < M; i++){
		for(j = 0; j < M; j++){
			if(grid[i][j] != grid[j][i]
			|| grid[i][j] != grid[M-1-i][M-1-j]
			|| grid[j][i] != grid[M-1-j][M-1-i]
			|| grid[M-1-j][M-1-i] != grid[M-1-i][M-1-j]
			) return 0;
		}
	}
	return M;
}

int main(void){
	int T, caseNo, ans;
	char s[TAM];
	scanf("%d\n", &T);
	for(caseNo = 1; caseNo <= T; caseNo++){
		fgets(s, TAM, stdin);
		ans = isMSP(s);
		printf("Case #%d:\n", caseNo);
		if(ans != 0) printf("%d\n", ans);
		else printf("No magic :(\n");
	}
	return 0;
}
