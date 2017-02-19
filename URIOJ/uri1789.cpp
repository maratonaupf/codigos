#include<stdio.h>

int main(void){	
	int l, v, i;
	while(scanf("%d", &l) != EOF){
		v = 0;
		while(l--){
			scanf("%d", &i);
			if(v < i) v = i;
		}
		printf("%d\n", v < 10 ? 1 : v < 20 ? 2 : 3);
	}
	return 0;
}
