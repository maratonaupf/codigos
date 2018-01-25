/*
 * Leonardo Deliyannis Constantin
 * UVa 10082 - WERTYU
 */

#include <stdio.h>
#define MAX 256

char t[MAX];

void setup(){
	int i;
	char w[] = "1234567890-=WERTYUIOP[]\\SDFGHJKL;'XCVBNM,./";
	char r[] = "`1234567890-QWERTYUIOP[]ASDFGHJKL;ZXCVBNM,.";
	for(i = 0; i < 255; i++){
		t[i] = (char) i;
	}
	for(i = 0; w[i]; i++){
		t[(int)w[i]] = r[i];
	}
}

void convert(char *s){
	for(int i = 0; s[i] != '\n'; i++){
		s[i] = t[(int)s[i]];
	}
}

int main(){
	char s[MAX];
	setup();
	while(fgets(s, MAX, stdin)){
		convert(s);
		printf("%s", s);
	}
	return 0;
}
