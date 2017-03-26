#include <stdio.h>
#include <string.h>
#define MAX 1123456

int memo[MAX];

int f91(int N){
	if(memo[N] == -1){
		memo[N] = (N <= 100) ? f91(f91(N + 11)) : N - 10;
	}
	return memo[N];
}

int main(){
	int N;
	memset(memo, -1, sizeof(memo));
	while(scanf("%d", &N), N != 0){
		printf("f91(%d) = %d\n", N, f91(N));
	}
	return 0;
}
