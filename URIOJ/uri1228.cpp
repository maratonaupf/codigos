/*
 * Leonardo Deliyannis Constantin
 * URI 1228 - Grid de Largada
 */

#include <stdio.h>
#define MAX 25

int invCount(int N, int v[]){
	int i, j, cnt = 0;
	for(i = 0; i < N; i++){
		for(j = i+1; j < N; j++){
			if(v[i] > v[j]) cnt++;
		}
	}
	return cnt;
}

int main(){
	int N, i, c;
	int tab[MAX], pos[MAX];
	while(scanf("%d", &N) != EOF){
		for(i = 0; i < N; i++){
			scanf("%d", &c);
			tab[c] = i;
		}
		for(i = 0; i < N; i++){
			scanf("%d", &c);
			pos[i] = tab[c];
		}
		printf("%d\n", invCount(N, pos));
	}
	return 0;
}
