#include<stdio.h>
#define INFTO 112345678

int main(void){
	int N, B, H, W;
	int i, p, a;
	int cheapest;
	while(scanf("%d %d %d %d", &N, &B, &H, &W) != EOF){
		cheapest = INFTO;
		while(H--){
			scanf("%d", &p);
			for(i = 0; i < W; i++){
				scanf("%d", &a);
				if(N <= a && p < cheapest){
					cheapest = p;
				}
			} 
		}
		if(cheapest * N <= B) printf("%d\n", cheapest * N);
		else printf("stay home\n");
	}
	return 0;
}
