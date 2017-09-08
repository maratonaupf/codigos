/*
 * Leonardo Deliyannis Constantin
 * UVa 507 - Jill Rides Again
 */

#include <stdio.h>

int main(){
	int B, R, rt, k, v;
	int ans, sum;
	int i, j, st;
	scanf("%d", &B);
	for(rt = 1; rt <= B; rt++){
		scanf("%d", &R);
		ans = sum = 0;
		st = i = 1;
		j = -1;
		for(k = 1; k < R; k++){
			scanf("%d", &v);
			sum += v;
			if(ans < sum || (ans == sum && k - st > j - i)){
				ans = sum;
				j = k;
				i = st;
			}
			if(sum < 0){
				sum = 0;
				st = k+1;
			}
		}
		if(ans > 0){
			printf("The nicest part of route %d ", rt);
			printf("is between stops %d and %d\n", i, j+1);
		}
		else printf("Route %d has no nice parts\n", rt);
	}
	return 0;
}
