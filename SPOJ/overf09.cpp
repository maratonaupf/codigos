#include<stdio.h>

int main(void){
	int N, P, Q;
	char op;
	while(scanf("%d\n", &N) != EOF){
		scanf("%d %c %d\n", &P, &op, &Q);
		printf("%s\n", (op == '+' ? P+Q : P*Q) > N ? "OVERFLOW" : "OK");
	}
	return 0;
}
