#include<stdio.h>
#include<stdlib.h>

int main(void){
	int a, b, resp;
	while(scanf("%d %d", &a, &b), a != -1 && b != -1){
		resp = abs(a-b);
		printf("%d\n", (resp < 100 - resp) ? resp : 100 - resp);
	}
	return 0;
}
