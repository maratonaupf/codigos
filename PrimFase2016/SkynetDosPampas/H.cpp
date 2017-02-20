#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 59

bool isvowel(char c){
	char vw[] = "aeiou";
	c = tolower(c);
	for(int i = 0; i < 5; i++){
		if(c == vw[i]) return true;
	}
	return false;
}


bool ispalin(char *s){
	int i, tam = (int)strlen(s);
	for(i = 0; i < tam / 2; i++){
		if(s[i] != s[tam - 1 - i]) return false;
	}
	return true;
}

bool isfunny(char *s){
	char v[MAX];
	int i, tam = 0;
	for(i = 0; s[i]; i++){
		if(isvowel(s[i])){ v[tam++] = s[i]; }
	} v[tam] = 0;
	return ispalin(v);
}

int main(void){
	char s[MAX];
	while(fgets(s, MAX, stdin) != NULL){
		s[(int)strlen(s)-1] = 0; // remove o \n
		printf("%c\n", isfunny(s) ? 'S' : 'N');
	}
	return 0;
}
