#include<stdio.h>
#include<algorithm>
#define MAX 112

// Kadane's Algorithm
// Largest Sum Contiguous Subarray

int kadane(int N, int v[]){
	int ret = v[0], maxAtual = v[0];
	for(int i = 1; i < N; i++){
		maxAtual = max(v[i], maxAtual + v[i]);
		ret = max(ret, maxAtual);
	}
	return ret;
}

int main(void){
	int T, N, v[MAX], i;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		for(i = 0; i < N; i++) scanf("%d", v+i);
		printf("%d\n", kadane(N, v));
	}
	return 0;
}
