/*
 * Leonardo Deliyannis Constantin
 * CodeForces 898A - Rounding
*/

#include <stdio.h>

int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		n += (n % 10 < 6) ? (- (n%10)) : (10 - (n%10));
		printf("%d\n", n);
	}
	return 0;
}
