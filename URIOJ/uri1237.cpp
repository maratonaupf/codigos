#include<stdio.h>
#include<string.h>
#define MAX 64
#define MSET(c,v) memset(c,v,sizeof(c))

int max(int a, int b){ return (a > b)? a : b; }

int lcs(char *X, char *Y, int m, int n){
	int i, j, t[MAX][MAX], ret = 0;
	t[0][0] = t[0][1] = t[1][0] = 0;
	for(i = 1; i<=m; i++){
		for(j = 1; j<=n; j++){
			if(X[i-1] == Y[j-1]){
				t[i][j] = t[i-1][j-1] + 1;
				ret = max(ret, t[i][j]);
			}else t[i][j] = 0;
		}
	}
	return ret;
}

int main(void){	
	char s[MAX], t[MAX];
	while(fgets(s, MAX, stdin) != NULL){
		fgets(t, MAX, stdin);
		int ts = strlen(s), tt = strlen(t);
		s[ts-1] = t[tt-1] = 0;
		printf("%d\n", lcs(s, t, strlen(s), strlen(t)));
	}
	return 0;
}
