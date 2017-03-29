#include <stdio.h>

int main(){
	int m, n, sum, tests = 0;
	char op;
	while(scanf("%d", &m), m != 0){
		tests++;
		sum = 0;
		while(m--){
			scanf("%c%d", &op, &n);
			sum += (op == '-') ? -n : n;
		}
		printf("Teste %d\n", tests);
		printf("%d\n\n", sum);
	}
	return 0;
}
