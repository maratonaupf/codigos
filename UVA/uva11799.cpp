#include<stdio.h>

int main(void){
	int T, caso, N, vel, clown;
	scanf("%d", &T);
	for(caso = 1; caso <= T; caso++){
		scanf("%d", &N);
		clown = -1;
		while(N--){
			scanf("%d", &vel);
			if(vel > clown){
				clown = vel;
			}
		}
		printf("Case %d: %d\n", caso, clown);
	}
	return 0;
}
