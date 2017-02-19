#include<stdio.h>
#include<ctype.h>
#define TAM 64
// macro que retorna o valor de cada jogada:
// - se for um algarismo, retorna-o como inteiro;
// - caso contrario (strike ou spare), retorna 10
#define valueOf(c) (isdigit(c) ? (c) - '0' : 10) 

int main(void){
	int i, score, rodadas;
	char s[TAM];
	while(fgets(s, TAM, stdin), s[0] != 'G'){
		score = rodadas = 0;
		for(i = 0; s[i] != '\0' && rodadas < 20; i+=2){
			if(s[i] == 'X'){
				if(s[i+4] == '/') score += 20;
				else score += 10 + valueOf(s[i+2]) + valueOf(s[i+4]);
				rodadas += 2;
			}
			else if(s[i] == '/'){
				score += 10 - valueOf(s[i-2]) + valueOf(s[i+2]);
				rodadas++;
			}
			else{
				score += valueOf(s[i]);
				rodadas++;
			}
		}
		printf("%d\n", score);
	}
	return 0;
}
