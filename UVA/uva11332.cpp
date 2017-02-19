#include<stdio.h>

int f(int n){
	int aux = 0;
	while(n > 0){
		aux += n % 10;
		n /= 10;
	}
	return aux;
}

int g(int n){
	while(n >= 10) n = f(n);
	return n;
}

int main(void){
	int n;
	while(scanf("%d", &n), n){
		printf("%d\n", g(n));
	}
	return 0;
}
