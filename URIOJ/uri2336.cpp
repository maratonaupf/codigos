/*
 * Leonardo Deliyannis Constantin
 * URI 2336 - ABC
 */

#include <stdio.h>
#include <string.h>
#define MAX 1123
#define P (ll(1e9)+7)

typedef long long ll;

ll expmod(ll x, ll n){
	if(n == 0) return 1;
	ll y = 1;
	while(n > 1){
		if(n&1){
			y *= x % P;
			y %= P;
		}
		x *= x % P;
		x %= P;
		n /= 2;
	}
	return ((x % P) * (y % P)) % P;
}

ll toInt(const char *s){
	ll ret = 0;
	int tam = strlen(s);
	for(int i = tam-1; i >= 0; i--){
		ret += ((s[i] - 'A') * expmod(26, tam-1-i)) % P;
		ret %= P;
	}
	return ret;
}

int main(){
	char s[MAX];
	while(fgets(s, MAX, stdin) != NULL){
		s[strlen(s)-1] = 0;
		printf("%lld\n", toInt(s));
	}
	return 0;
}
