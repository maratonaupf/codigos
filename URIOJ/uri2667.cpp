/*
 * Leonardo Deliyannis Constantin
 * URI 2667 - Jogo de Boca (Maratona SBC 2017)
 */

#include <stdio.h>
#define LEN 112

int main(){
	int x, i;
	char s[LEN];
	while(fgets(s, LEN, stdin) != NULL){
		x = 0;
		for(i = 0; s[i] != '\n'; i++){
			x += (s[i] - '0') % 3;
		}
		printf("%d\n", x%3);
	}
	return 0;
}
