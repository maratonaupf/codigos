/* Solução de Marcelo Cezar Pinto */

#include<stdio.h>

int main(void) {
	int n, W, v[101], w[101], S[101], i, j, caso=1;

	scanf("%d %d", &W, &n);
	while (n) {
		for (i = 1; i <= n; i++) 
		    scanf("%d", &w[i]);
		for (i = 1; i <= n; i++) 
		    scanf("%d", &v[i]);
		for (i = 0; i <= W; i++) 
		    S[i] = 0;
		for (j = 1; j <= n; j++)
    		for (i = W; i >= 1; i--)
	        	if (w[j] <= i && S[i] < S[i-w[j]] + v[j])
            		S[i] = S[i-w[j]] + v[j];
		printf("Caso %d gera felicidade %d\n", caso++, S[W]);
		scanf("%d %d", &W, &n);
	}
	return 0;
}

