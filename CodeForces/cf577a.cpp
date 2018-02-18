/*
 * Leonardo Deliyannis Constantin
 * CodeForces 577A - Multiplication Table
 */

#include <stdio.h>

int main(){
	int n, x, a, i;
	while(scanf("%d %d", &n, &x) != EOF){
		a = 0;
		for(i = 1; i <= n; i++){
			if(x%i == 0 && x/i <= n) a++;
		}
		printf("%d\n", a);
	}
	return 0;
}
