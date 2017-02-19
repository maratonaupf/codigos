#include<stdio.h>

int main(void){
	int i;
	double final, max, min, atual;
	while(scanf("%lf", &atual) != EOF){
		final = atual;
		max = min = atual;
		for(i = 1; i < 5; i++){
			scanf("%lf", &atual);
			final += atual;
			if(max < atual) max = atual;
			if(min > atual) min = atual;
		}
		final -= max;
		final -= min;
		printf("%.1lf\n", final);
	}
	return 0;
}
