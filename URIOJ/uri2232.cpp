#include<stdio.h>

int main(void){
	int n, nc;
	scanf("%d", &nc);
	while(nc--){
		scanf("%d", &n);
		printf("%d\n", (1<<n)-1);
	}
	return 0;
}
