#include<stdio.h>
#include<string.h>
#define MAX 21

int main(void){
	int N, M, C, i, dev, tc = 0;
	int p, c[MAX], top;
	bool on[MAX], blown;
	while(scanf("%d %d %d", &N, &M, &C), N || M || C){
		for(i = 1; i <= N; i++){
			scanf("%d", c+i);
		}
		p = top = 0;
		memset(on, 0, sizeof(on));
		blown = false;
		for(i = 0; i < M; i++){
			scanf("%d", &dev);
			on[dev] = !on[dev];
			p += on[dev] ? c[dev] : -c[dev];
			if(p > C) blown = true;
			if(p > top) top = p;
		}
		printf("Sequence %d\n", ++tc);
		printf("Fuse was%s blown.\n", blown ? "" : " not");
		if(!blown) printf("Maximal power consumption was %d amperes.\n", top);
		printf("\n");
	}
	return 0;
}
