/*
 * Leonardo Deliyannis Constantin
 * CodeForces 688 B - Lovely Palindromes
 */

#include <stdio.h>
#include <string.h>
#define MAX 212345

void mirrorForce(char *s){
	int i, tam = strlen(s)-1;
	for(i = 0; i < tam; i++){
		s[tam*2-1-i] = s[i];
	}
	s[tam*2] = 0;
}

int main(){
	char s[MAX];
	while(fgets(s, MAX, stdin)){
		mirrorForce(s);
		printf("%s\n", s);
	}
	return 0;
}
