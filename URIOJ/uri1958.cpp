#include<stdio.h>

int main(void){
	double x;
	while(scanf("%lf", &x) != EOF){
		printf("%+.4E\n", x);
	}
	return 0;
}
