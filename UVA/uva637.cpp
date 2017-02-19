#include<stdio.h>

int N;
void printPages(int a, int b){
	if(a > N) printf("Blank, ");
	else printf("%d, ", a);
	if(b > N) printf("Blank\n");
	else printf("%d\n", b);
}

int main(void){
	int limit, i;
	while(scanf("%d", &N), N != 0){
		printf("Printing order for %d pages:\n", N);
		if(N == 1){
			printf("Sheet 1, front: Blank, 1\n");
			continue;
		}
		limit = (N % 4 == 0) ? N : N + 4 - (N%4);
		for(i = 0; i < limit/2; i++){
			printf("Sheet %d, %s: ", (i+2)/2, (i&1) ? "back " : "front");
			if(i&1) printPages(i+1, limit-i);
			else printPages(limit-i, i+1);
		}
	}
	return 0;
}
