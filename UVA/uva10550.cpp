#include<stdio.h>

int main(void){
	int a, b, c, d, resp;
	while(scanf("%d %d %d %d", &a, &b, &c, &d), a || b || c || d){
		resp = 120;
		resp += (b > a) ? (40 - b + a) : (a - b); 
		resp += (b > c) ? (40 - b + c) : (c - b); 
		resp += (d > c) ? (40 - d + c) : (c - d); 
		printf("%d\n", resp * 9);
	}
	return 0;
}
