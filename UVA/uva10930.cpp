#include<stdio.h>
#define MAX 31

bool isSubsetSum(int set[], int n, int sum){
	// If sum is zero, then it always exists in any set
	if (sum == 0) return true;
	// If set is empty and sum isn't zero, it doesn't exist in the set
	if (n == 0 && sum != 0) return false;
   // If last element is greater than sum, then ignore it
	if (set[n-1] > sum) 
		return isSubsetSum(set, n-1, sum);
	
	return isSubsetSum(set, n-1, sum) || 
		isSubsetSum(set, n-1, sum-set[n-1]);
}

int main(void){	
	int N, v[MAX], tc = 0, i;
	bool flag;
	while(scanf("%d", &N) != EOF){
		flag = true;
		printf("Case #%d:", ++tc);
		for(i = 0; i < N; i++){ 
			scanf("%d", v+i); printf(" %d", v[i]);
			if(i){ if(v[i-1] >= v[i]) flag = false; }
			if(flag && (i > 1) && isSubsetSum(v, N, v[i])) flag = false;
		}
		printf("\nThis is%s an A-sequence.\n", flag ? "" : " not");
	}
	return 0;
}
