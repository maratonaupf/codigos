#include<stdio.h>

int main(void){
	int N, P;
	int f1, f2, cont;
	while(scanf("%d %d", &N, &P) != EOF){
		cont = 0;
		while(N--){
			scanf("%d %d", &f1, &f2);
			if(P <= f1 + f2) cont++;
		}
		printf("%d\n", cont);
	}
	return 0;
}
