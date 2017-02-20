#include<stdio.h>

int main(void){
	int N, A, B;
	int VA, VB;
	while(1){
		scanf("%d", &N);
		if(N == 0){
			break;
		}
		VA = VB = 0;
		while(N--){
			scanf("%d %d", &A, &B);
			if(A > B) VA++;
			if(A < B) VB++;
		}
		printf("%d %d\n", VA, VB);
	}
	return 0;
}
