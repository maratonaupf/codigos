/*
 * Leonardo Deliyannis Constantin
 * URI 2253 - Validador de Senhas
 */

#include <stdio.h>
#include <ctype.h>
#define MAX 112345
char s[MAX];

bool isValid(const char *s){
	int i;
	bool num, lo, up;
	num = lo = up = false;
	for(i = 0; s[i] != '\n'; i++){
		if(ispunct(s[i]) || isspace(s[i]) || i == 32) 
			return false;
		if(isdigit(s[i])) num = true;
		if(islower(s[i])) lo = true;
		if(isupper(s[i])) up = true;
	}
	return num && lo && up && i >= 6;
}

int main(){
	while(fgets(s, MAX, stdin) != NULL){
		printf("Senha %svalida.\n", isValid(s) ? "" : "in");
	}
	return 0;
}
