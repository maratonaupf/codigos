#include<stdio.h>
#include<ctype.h>
#define MAX 64

int isvowel(int c){
	c = tolower(c);
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; 
}

int isfunny(char *s, int tam){
	int i;
	for(i = 0; i < tam / 2; i++){
		if(s[i] != s[tam - i - 1]) return 0;
	}
	return 1;
}

int main(void){
	int c, tam = 0;
	char s[MAX];
	while((c = getchar()) != EOF){
		if(isvowel(c)) s[tam++] = c;
		else if(c == '\n'){
			s[tam] = 0;
			printf("%c\n", isfunny(s, tam) ? 'S' : 'N');
			tam = 0;
		}
	}
	return 0;
}
