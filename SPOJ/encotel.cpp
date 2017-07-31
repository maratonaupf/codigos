/*
 * Leonardo Deliyannis Constantin
 * http://br.spoj.com/problems/ENCOTEL/
 */

#include <stdio.h>
#include <ctype.h>
#define LEN 32

int m[26];
void setmap(){
	int i = 0;
	for(; i <  3; i++) m[i] = '2';
	for(; i <  6; i++) m[i] = '3';
	for(; i <  9; i++) m[i] = '4';
	for(; i < 12; i++) m[i] = '5';
	for(; i < 15; i++) m[i] = '6';
	for(; i < 19; i++) m[i] = '7';
	for(; i < 22; i++) m[i] = '8';
	for(; i < 26; i++) m[i] = '9';
}

int main(){
	int i;
	char s[LEN];
	setmap();
	while(fgets(s, LEN, stdin) != NULL){
		for(i = 0; s[i] != '\n'; i++){
			if(isalpha(s[i])) s[i] = m[s[i] - 'A'];
		}
		printf("%s", s);
	}
	return 0;
}
