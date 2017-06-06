/*
 * Leonardo Deliyannis Constantin
 * UVa 11278 - One-Handed Typist
 */

#include <stdio.h>
#include <string.h>
#include <assert.h>
#define MAX 1123

char mapped[256];
void populate_map(){
	int i, tam;
	const char qwerty[] = 
		"`1234567890-="
		"qwertyuiop[]\\"
		"asdfghjkl;'"
		"zxcvbnm,./"

		"~!@#$%^&*()_+"
		"QWERTYUIOP{}|"
		"ASDFGHJKL:\""
		"ZXCVBNM<>?"
	;
	const char dvorak[] = 
		"`123qjlmfp/[]"
		"456.orsuyb;=\\"
		"789aehtdck-"
		"0zx,inwvg'"

		"~!@#QJLMFP?{}"
		"$%^>ORSUYB:+|"
		"&*(AEHTDCK_"
		")ZX<INWVG\""
	;
	tam = strlen(qwerty);
	memset(mapped, 0, sizeof(mapped));
	for(i = 0; i < tam; i++){
		mapped[(int)qwerty[i]] = dvorak[i];
	}
}

void toDvorak(char *s){
	int i;
	for(i = 0; s[i] != '\n'; i++){
		if(mapped[(int) s[i]] != 0)
			s[i] = mapped[(int)s[i]];
	}
	s[i] = 0;
}

int main(){
	populate_map();
	char s[MAX];
	while(fgets(s, MAX, stdin)){
		toDvorak(s);
		puts(s);
	}
	return 0;
}
