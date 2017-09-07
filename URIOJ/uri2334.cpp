/*
 * Leonardo Deliyannis Constantin
 * URI 2334 - Patinhos
*/

#include <stdio.h>
#define LEN 22

typedef unsigned long long ull;

ull stoull(const char *s){
	int i;
	ull ret = 0ULL;
	for(i = 0; s[i]; i++){
		ret *= 10ULL;
		ret += (ull)(s[i] - '0');
	}
	return ret;
}

int main(){
	ull p;
	char s[LEN];
	while(scanf(" %s", s), s[0] != '-'){
		p = stoull(s);
		if(p > 0ULL) p--;
		printf("%llu\n", p);
	}
	return 0;
}
