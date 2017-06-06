/*
 * Leonardo Deliyannis Constantin
 * UVa 458 - The Decoder
*/

#include<stdio.h>
#include<string.h>
#define MAX 112345

void decode(char *s){
	int i;
	for(i = 0; s[i] != '\n'; i++)
		s[i] -= 7;
}

int main(){
	char s[MAX];
	while(fgets(s, MAX, stdin)){
		decode(s);
		printf("%s", s);
	}
	return 0;
}
