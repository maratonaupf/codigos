#include <stdio.h>

int main(){
	int N, i, c, v, total;
	while(scanf("%d", &N), N != 0){
		total = 0;
		for(i = 0; i < N; i++){
			scanf("%d %d", &c, &v);
			// se a quantidade de varetas for ímpar, descartamos uma
			if(v%2 == 1) v--;
			total += v;
		}
		printf("%d\n", total / 4);
	}
	return 0;
}
