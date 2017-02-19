#include<stdio.h>
#define min(x, y) (((x) < (y)) ? (x) : (y))

int main(void){
	int a, b, c;
	while(scanf("%d %d %d", &a, &b, &c) != EOF){
		a /= 2;
		b /= 3;
		c /= 5;
		printf("%d\n", min(min(a,b), c));
	}
	return 0;
}
