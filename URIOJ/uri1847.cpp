#include<stdio.h>

int main(void){
	int A, B, C;
	bool happy;
	while(scanf("%d %d %d", &A, &B, &C) != EOF){
		happy = 0;
		if(A > B){
			happy = (B <= C) ? 1 : (A-B > B-C) ? 1 : 0;
		}
		if(A < B){
			happy = (B >= C) ? 0 : (B-A > C-B) ? 0 : 1;
		}
		if(A == B){
			happy = (B < C);
		}
		printf(":%c\n", happy ? ')' : '(');
	}
	return 0;
}
