#include<stdio.h>

int main(void){
	int T, i, a, b, c, total;
	scanf("%d", &T);
	for(i = 1; i <= T; i++){
		scanf("%d %d %d", &a, &b, &c);
		total = a+b+c;
		/* cortando o maior salario */
		if(a > b && a > c) total -= a;
		if(b > a && b > c) total -= b;
		if(c > a && c > b) total -= c;
		
		/* cortando o menor salario */
		if(a < b && a < c) total -= a;
		if(b < a && b < c) total -= b;
		if(c < a && c < b) total -= c;
		printf("Case %d: %d\n", i, total);
	}
	return 0;
}
