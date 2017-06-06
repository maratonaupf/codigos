/*
 * Leonardo Deliyannis Constantin
 * UVa 10878 - Decode The Tape
 */

#include <stdio.h>
#include <string.h>
#define LEN 13
#define MAX 112345

const int val[] = {0, 0, 64, 32, 16, 8, 0, 4, 2, 1, 0 };

int tapeToAscii(const char *s){
	int i, ret = 0;
	for(i = 0; i < 11; i++){
		if(s[i] == 'o') ret += val[i]; 
	}
	return ret;
}

int main(){
	int tam = 0;
	char s[LEN];
	char out[MAX];
	fgets(s, LEN, stdin);
	while(fgets(s, LEN, stdin), strcmp(s, "___________\n")){
		out[tam++] = tapeToAscii(s);
		if(out[tam-1] == '\r')
			out[tam-1] = '\n';
	}
	out[tam] = 0;
	printf("%s", out);
	return 0;
}
