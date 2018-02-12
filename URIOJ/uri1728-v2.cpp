/*
 * Leonardo Deliyannis Constantin
 * URI 1728 - Difícil de Acreditar, Mas é Verdade!
 */

#include <stdio.h>
#include <string.h>
#define LEN 11

int conv(const char *s){
	int ret = 0;
	for(int i = strlen(s) - 1; i >= 0; i--){
		ret *= 10;
		ret += s[i] - '0';
	}
	return ret;
}

int main(){
	char s[33];
	char a[LEN], b[LEN], c[LEN];
	int x, y, z;
	while(scanf("%s", s) != EOF){
		strcpy(a, strtok(s, "+="));
		strcpy(b, strtok(NULL, "+="));
		strcpy(c, strtok(NULL, "+="));
		x = conv(a), y = conv(b), z = conv(c);
		printf("%s\n", (x + y == z) ? "True" : "False");
		if(!(x || y || z)) break;
	}
	return 0;
}
