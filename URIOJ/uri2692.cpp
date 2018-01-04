/*
 * Leonardo Deliyannis Constantin
 * URI 2692 - Teclado Zoeiro
 */

#include <stdio.h>
#include <string.h> /* memset() */
#include <ctype.h>  /* toupper(), tolower() */
#define MAX 112345

int mymap[256];

void unswapLetters(char *s){
	int i;
	for(i = 0; s[i] != '\n'; i++)
		if(mymap[(int)s[i]] != -1)
			s[i] = mymap[(int)s[i]];
}

int main(){
	int N, M;
	char a, b;
	char s[MAX];
	while(scanf("%d %d\n", &N, &M) != EOF){
		memset(mymap, -1, sizeof(int) * 256);
		while(N--){
			scanf("%c %c\n", &a, &b);
			mymap[toupper(a)] = toupper(b);
			mymap[tolower(a)] = tolower(b);
			mymap[toupper(b)] = toupper(a);
			mymap[tolower(b)] = tolower(a);
		}
		while(M--){
			scanf (" %[^\n]s", s);
			unswapLetters(s);
			printf("%s\n", s);
		}
	}
	return 0;
}
