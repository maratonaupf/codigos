/*
 * Leonardo Deliyannis Constantin
 * http://br.spoj.com/problems/PALAVRMG/
 */

#include <stdio.h>
#include <ctype.h>
#define LEN 44

int main(){
	int N, i;
	bool ord;
	char s[LEN];
	scanf("%d\n", &N);
	while(N--){
		scanf("%s\n", s);
		ord = true;
		for(i = 1; s[i]; i++){
			if(tolower(s[i-1]) >= tolower(s[i])) ord = false;
		}
		printf("%s: %c\n", s, ord ? 'O' : 'N');
	}
	return 0;
}
