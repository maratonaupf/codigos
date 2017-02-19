#include<stdio.h>
#define MAX 112345

int main(void){
	int S, B, L, R, i;
	int left[MAX], right[MAX];
	while(scanf("%d %d", &S, &B), S != 0){
		for(i = 1; i <= S; i++){
			left[i] = i-1;
			right[i] = i+1;
		}
		while(B--){
			scanf("%d %d", &L, &R);
			(left[L] > 0) ? printf("%d ", left[L]) : printf("* ");
			(right[R] <= S) ? printf("%d\n", right[R]) : printf("*\n");
			right[left[L]] = right[R];
			left[right[R]] = left[L];
		}
		printf("-\n");
	}
	return 0;
}
