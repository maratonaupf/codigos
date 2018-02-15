/*
 * Leonardo Deliyannis Constantin
 * URI 2292 - Painel LED
 */

#include <stdio.h>
#include <string.h>
#define MAX 64

typedef long long ll;

void alter(char *s, ll c){
	ll d = 0LL;
	for(int i = strlen(s)-1; i >= 0; i--){
		d <<= 1LL;
		d += s[i] == 'O';
	}
	d += c;
	for(int i = 0; s[i]; i++){
		s[i] = (d&1) ? 'O' : 'X';
		d >>= 1LL;
	}
}

int main(){
	int N;
	ll c;
	char s[MAX];
	scanf("%d", &N);
	while(N--){
		scanf("%s %lld", s, &c);
		alter(s, c);
		printf("%s\n", s);
	}
	return 0;
}
