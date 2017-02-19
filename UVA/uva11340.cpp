#include<stdio.h>
#include<string.h>
#define MAX 11234

int val[256];

int main(void){
	int N, K, M, i;
	int c, tam;
	double amount;
	char s[MAX];
	scanf("%d\n", &N);
	while(N--){
		amount = 0.0;
		memset(val, 0, sizeof(val));
		scanf("%d\n", &K);
		while(K--){
			c = getchar();
			scanf(" %d\n", &val[c]);
		}
		scanf("%d\n", &M);
		while(M--){
			fgets(s, MAX, stdin);
			tam = strlen(s)-1;
			for(i = 0; i < tam; i++){
				amount += (double) val[(unsigned char)s[i]] / 100.0;
			}
		}
		printf("%0.2lf$\n", amount);
	}
	return 0;
}
