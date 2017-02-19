#include<stdio.h>

int main(void){
	int N, a, b;
	scanf("%d", &N);
	while(N--){
		scanf("%d %d", &a, &b);
		printf("%c\n", a < b ? '<' : a > b ? '>' : '=');
	}
	return 0;
}
