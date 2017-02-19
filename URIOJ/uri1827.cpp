#include<stdio.h>
#include<string.h>
#define MAX 112

int main(void){
	int m[MAX][MAX], i, j, N, b, e;
	while(scanf("%d", &N) != EOF){
		memset(m, 0, sizeof(m));
		b = N/3; e = N-b;
		for(i = 0; i < N; i++){
			m[i][i] = 2;
			m[i][(N-1) - i] = 3;
			for(j = 0; j < N; j++){
				if(b <= i && b <= j && i < e && j < e)
					m[i][j] = 1;
				if(i == (N-1) - i && i == j)
					m[i][j] = 4;
				printf("%d", m[i][j]); 
			} putchar('\n');
			
		}
		putchar('\n');
	}
	return 0;
}
