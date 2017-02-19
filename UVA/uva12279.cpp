#include<stdio.h>

int main(void){
	int N, i, r, t;
	int tc = 0;
	while(scanf("%d", &N), N){
		r = t = 0;
		while(N--){
			scanf("%d", &i);
			i ? r++ : t++;
		}
		printf("Case %d: %d\n", ++tc, r-t);
	}
	return 0;
}
