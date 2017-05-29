/*
 * Leonardo Deliyannis Constantin
 * Maratona Mineira 2017 - Problema B: A Bruxa do 7x1
 */

#include <stdio.h>

int zerify(int n){
	int i, aux = n;
	for(i = 1e9; i >= 1; i /= 10){
		if(aux/i == 7) n -= 7*i;
		aux %= i;
	}
	return n;
}

int main(){
	int a, b;
	char op;
	while(scanf("%d %c %d\n", &a, &op, &b) != EOF){
		a = zerify(a);
		b = zerify(b);
		//fprintf(stderr, "%d %d\n", a, b);
		printf("%d\n", zerify(op == '+' ? a+b : a*b));
	}
	return 0;
}
