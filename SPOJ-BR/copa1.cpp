#include<stdio.h>

int main(void){
	int M, N, i;
	char vencedor[15];
	while(scanf("%d %d", &M, &N) != EOF){
		vencedor[0] = M > N ? 'A' : 'B';
		for(i = 1; i < 15; i++){
			scanf("%d %d", &M, &N);
			vencedor[i] = (i < 8) ? ('A' + i*2 + (M > N ? 0 : 1)) :
				vencedor[(2*i-16) + (M > N ? 0 : 1)];
		}
		printf("%c\n", vencedor[14]);
	}
	return 0;
}
