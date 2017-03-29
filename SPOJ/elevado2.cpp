#include <stdio.h>

int main(){
	int N, C, S, E, pessoas;
	char resp;
	while(scanf("%d %d", &N, &C) != EOF){
		pessoas = 0;
		resp = 'N';
		while(N--){
			scanf("%d %d", &S, &E);
			pessoas -= S;
			pessoas += E;
			if(pessoas > C) resp = 'S';
		}
		printf("%c\n", resp);
	}
	return 0;
}
