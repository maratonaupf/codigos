#include<stdio.h>

int main(void){
	int T, N;
	while(scanf("%d", &T), T){
		while(T--){
			scanf("%d", &N);
			printf("%d\n", (N-1)*2 + (N&1));
		}
	}
	return 0;
}
