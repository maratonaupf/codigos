/*
 * Leonardo Deliyannis Constantin
 * CodeForces 50B - Choosing Symbol Pairs
 */

#include <stdio.h>
#include <string.h>
#define MAX 112345

typedef long long ll;

int main(){
	int i, c;
	int cnt[128];
	char s[MAX];
	ll n;
	while(fgets(s, MAX, stdin) != NULL){
		memset(cnt, 0, sizeof(cnt));
		for(i = 0; s[i] != '\n'; i++){
			cnt[(int)s[i]]++;
		}
		n = 0LL;
		// algarismos vem antes de letras
		// minúsculas na tabela ASCII
		for(c = '0'; c <= 'z'; c++){
			n += (ll) cnt[c]*cnt[c];
		}
		printf("%lld\n", n);
	}
	return 0;
}
