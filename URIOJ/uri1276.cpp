/*
 * Leonardo Deliyannis Constantin
 * URI 1276 - Faixa de Letras
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LEN 55

int oc[27];

void count(const char *s){
	memset(oc, 0, sizeof(oc));
	for(int i = 0; s[i] != '\n'; i++){
		if(isalpha(s[i])) oc[s[i] - 'a'] = 1;
	}
}

int main(){
	char s[LEN];
	while(fgets(s, LEN, stdin)){
		count(s);
		bool on = false, first = true;
		for(int i = 0; i <= 26; i++){
			if(oc[i]){
				if(!on){
					if(first) first = false;
					else printf(", ");
					printf("%c:", i+'a');
					on = true;
				}
			}
			else{
				if(on){
					on = false;
					printf("%c", (i-1)+'a');
				}
			}
		}
		printf("\n");
	}
	return 0;
}
