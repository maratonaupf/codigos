#include<stdio.h>
#define P 1000000009LL

int fat(int N){
	long long ret = 1;
	for(int i = N; i > 3; i--){
		ret *= i;
		ret %= P;
	}
	return (int)ret;
}

int main(void){
	int N;
	while(scanf("%d", &N), N){
		printf("%d\n", fat(N));
	}
	return 0;
}
