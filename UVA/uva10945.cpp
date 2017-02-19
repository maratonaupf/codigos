#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 512

void preprocess(char *s){
	int i, tam;
	s[tam = strlen(s)-1] = '\0';
	for(i = 0; i < tam; i++){
		if(!isalpha(s[i])){
			memmove(s+i, s+i+1, tam-i);
			tam--;
			i--;
		}
		else s[i] = toupper(s[i]);
	}
}

int safe(char *s){
	int i, tam;
	preprocess(s);
	tam = strlen(s);
	for(i = 0; i < tam/2; i++){
		if(s[i] != s[tam-1-i]) return 0;
	}
	return 1;
}

int main(void){
	char s[MAX];
	while(fgets(s, MAX, stdin), strcmp(s, "DONE\n") != 0){
		puts(safe(s) ? "You won't be eaten!" : "Uh oh..");
	}
	return 0;
}
