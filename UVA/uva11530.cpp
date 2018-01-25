/*
 * Leonardo Deliyannis Constantin
 * UVa 11530 - SMS Typing
 */

#include <stdio.h>
#include <string.h>
#define MAX 112

int m[256];

void setup(){
	memset(m, 0, sizeof(m));
	char s[] = "abcdefghijklmnopqrtuvwxy ";
	for(int i = 0; s[i]; i++){
		m[(int)s[i]] = 1 + (i%3);
	}
	m['s'] = m['z'] = 4;
}

int keypresses(const char *s){
	int ret = 0;
	for(int i = 0; s[i] != '\n'; i++){
		ret += m[(int)s[i]];
	}
	return ret;
}

int main(){
	int T;
	char s[MAX];
	setup();
	scanf("%d", &T);
	getchar();
	for(int t = 1; t <= T; t++){
		fgets(s, MAX, stdin);
		printf("Case #%d: %d\n", t, keypresses(s));
	}
	return 0;
}
