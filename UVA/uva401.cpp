#include<stdio.h>
#include<string.h>
#define MAX 22

char reverse[256];
void setReverseChars(){
	memset(reverse, 0, sizeof(reverse));
	reverse['A'] = 'A';
	reverse['E'] = '3';
	reverse['H'] = 'H';
	reverse['I'] = 'I';
	reverse['J'] = 'L';
	reverse['L'] = 'J';
	reverse['M'] = 'M';
	reverse['O'] = 'O';
	reverse['S'] = '2';
	reverse['T'] = 'T';
	reverse['U'] = 'U';
	reverse['V'] = 'V';
	reverse['W'] = 'W';
	reverse['X'] = 'X';
	reverse['Y'] = 'Y';
	reverse['Z'] = '5';
	reverse['1'] = '1';
	reverse['2'] = 'S';
	reverse['3'] = 'E';
	reverse['5'] = 'Z';
	reverse['8'] = '8';
}

int isMirrored(char *s){
	int i, tam;
	tam = strlen(s);
	for(i = 0; i < tam; i++){
		if(reverse[(int)s[i]] != s[tam-1-i]) return 0;
	}
	return 1;
}

int isPalindrome(char *s){
	int i, tam;
	tam = strlen(s);
	for(i = 0; i < tam/2; i++){
		if(s[i] != s[tam-1-i]) return 0;
	}
	return 1;
}

int main(void){
	char s[MAX];
	int flags;
	const char result[4][MAX] = {
		"not a palindrome", 
		"a regular palindrome", 
		"a mirrored string", 
		"a mirrored palindrome"
	};
	setReverseChars();
	while(fgets(s, MAX, stdin) != NULL){
		/* remove trailing '\n' */
		s[strlen(s) - 1] = '\0';
		flags = isMirrored(s) << 1;
		flags |= isPalindrome(s);
		printf("%s -- is %s.\n\n", s, result[flags]);
	}
	return 0;
}
