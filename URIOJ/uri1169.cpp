/*
 * Leonardo D. Constantin
 * URI 1169 - Trigo no Tabuleiro
 */

#include<stdio.h>

typedef unsigned long long ull;

int main(void){
	int N, i, x;
	ull mask;
	scanf("%d", &N);
	while(N--){
		scanf("%d", &x);
		mask = 0ULL;
		for(i = 0; i < x; i++){
			mask |= 1ULL << i;
		}
		printf("%llu kg\n", mask / 12000);
	}
	return 0;
}
