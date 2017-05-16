#include<stdio.h>

int main(){
	int N, D, A;
	while(scanf("%d %d %d", &N, &D, &A) != EOF){
		printf("%d\n", (D < A) ? N+D - A : D-A);
	}
	return 0;
}
