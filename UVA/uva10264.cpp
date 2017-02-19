#include<stdio.h>
#define MAX 32768

int main(void){
	int N, i, j, v[MAX];
	int sum[MAX], maxSum, currSum;
	while(scanf("%d", &N) != EOF){
		for(i = 0; i < (1 << N); i++){
			scanf("%d", v+i);
		}
		for(i = 0; i < (1 << N); i++){
			sum[i] = 0;
			for(j = 0; j < N; j++){
				sum[i] += v[i ^ (1<<j)];
			}
		}
		maxSum = 0;
		for(i = 0; i < (1 << N); i++){
			for(j = 0; j < N; j++){
				currSum = sum[i] + sum[i ^ (1<<j)];
				if(currSum > maxSum) maxSum = currSum;
			}
		}
		printf("%d\n", maxSum);
	}
	return 0;
}
