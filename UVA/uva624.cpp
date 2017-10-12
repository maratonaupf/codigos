/*
 * Leonardo Deliyannis Constantin
 * UVa 624 - CD
 */

#include <stdio.h>
#include <algorithm>
using namespace std;

int N, T, t[21];
int bestSum, chosen;

int backtrack(int i, int sum, int want){
	if(sum > bestSum){
		bestSum = sum;
		chosen = want;
	}
	if(i == T) return sum;
	if(sum + t[i] > N){
		return backtrack(i+1, sum, want);
	}
	int take = backtrack(i+1, sum + t[i], want | (1<<i)),
		leave = backtrack(i+1, sum, want);
	return max(take, leave);
}

int main(){
	int i;
	while(scanf("%d", &N) != EOF){
		scanf("%d", &T);
		for(i = 0; i < T; i++){
			scanf("%d", &t[i]); }
		bestSum = chosen = 0;
		backtrack(0, 0, 0);
		for(i = 0; i < T; i++){
			if(chosen & (1<<i)){
				printf("%d ", t[i]); }}
		printf("sum:%d\n", bestSum);
	}
	return 0;
}
