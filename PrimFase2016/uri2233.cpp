#include<stdio.h>

int main(void){
	unsigned long long R, G, B, resp;
	while(scanf("%llx", &R) != EOF){
		scanf("%llx %llx", &G, &B);
		resp = (R/G) * (R/G);
		resp += resp * (G/B) * (G/B) + 1;
		printf("%llx\n", resp);
	}
	return 0;
}
