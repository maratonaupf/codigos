#include<stdio.h>
#include<string.h>
#define MAX 72
#define DEBP

int main(void){
	int N, L, C;
	int x, k, c;
	char p[MAX];
	while(scanf("%d %d %d", &N, &L, &C) != EOF){
		scanf("%s", p);
		x = c = strlen(p);
		k = 1;
		while(--N){
			scanf("%s", p);
			c = strlen(p);
			if((x + 1 + c) <= C){
				x += 1 + c;
			}
			else{
				x = c;
				k++;
			}
		}
		printf("%d\n", (k+(L-1))/L);
	}
	return 0;
}
