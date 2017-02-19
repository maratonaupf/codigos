#include<stdio.h>
#include<stdlib.h>

int main(void){
	int L, c, i;
	int R, D, dist;
	while(scanf("%d\n", &L), L){
		dist = L;
		R = D = 0;
		for(i = 1; i <= L; i++){
			c = getchar();
			if(c == 'Z') dist = 0;
			if(c == 'R') R = i;
			if(c == 'D') D = i;
			if(R && D && abs(R-D) < dist) dist = abs(R-D);
		}
		printf("%d\n", dist);
	}
	return 0;
}
