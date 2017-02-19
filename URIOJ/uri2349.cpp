#include<stdio.h>
#define MAX 1123

int main(void){
	int N, C, S, cmd, i, cont, pos;
	while(scanf("%d %d %d", &N, &C, &S) != EOF){
		pos = 1;
		cont = (pos == S);
		for(i = 0; i < C; i++){
			scanf("%d", &cmd);
			pos += cmd;
			if(pos > N) pos = 1;
			if(pos < 1) pos = N;
			cont += (pos == S);
		}
		printf("%d\n", cont);
	}
	return 0;
}
