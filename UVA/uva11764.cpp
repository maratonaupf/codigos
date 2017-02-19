#include<stdio.h>

int main(void){
	int cn = 0, curr, b4;
	int t, n, hi, lo;
	scanf("%d", &t);
	while(t--){
		hi = lo = 0;
		scanf("%d", &n);
		scanf("%d", &b4);
		while(--n){
			scanf("%d", &curr);
			if(b4 < curr) hi++;
			if(b4 > curr) lo++;
			b4 = curr;
		}
		printf("Case %d: %d %d\n", ++cn, hi, lo);
	}
	return 0;
}
