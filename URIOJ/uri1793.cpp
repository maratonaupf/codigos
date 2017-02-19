#include<stdio.h>

int main(void){
	int N, t, a, b;
	while(scanf("%d", &N), N){
		scanf("%d", &a);
		t = 10;
		while(--N){
			scanf("%d", &b);
			t += b-a < 10 ? b-a : 10;
			a = b;
		}
		printf("%d\n", t);
	}
	return 0;
}
