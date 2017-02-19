#include<stdio.h>
#include<string.h>
#define MAX 11234

int main(void){
	int k, m, c, r, ccr, count;
	bool v[MAX], valid;
	while(scanf("%d", &k), k){
		scanf("%d", &m);
		memset(v, 0, sizeof(v));
		while(k--){
			scanf("%d", &ccr);
			v[ccr] = true;
		}
		valid = true;
		while(m--){
			scanf("%d %d", &c, &r);
			count = 0;
			while(c--){
				scanf("%d", &ccr);
				if(v[ccr]) count++;
			}
			if(count < r) valid = false;
		}
		puts(valid ? "yes" : "no");
	}
	return 0;
}
