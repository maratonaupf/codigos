#include<stdio.h>

int main(){
	int a, b;
	while(scanf("%d %d", &a, &b), a != 0){
		printf("%d\n", a + b);
	}
	return 0;
}

