#include<stdio.h>
#include<math.h>
#define bra(m) (unsigned)(floor((long double)m     / 90.0))
#define ger(m) (unsigned)(ceil((long double)m*7.0 / 90.0))

int main(void){
	int n;
	while(scanf("%d", &n), n){
		printf("Brasil %u x Alemanha %u\n", bra(n), ger(n));
	}
	return 0;
}
