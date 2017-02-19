#include<stdio.h>
#include<string.h>
#define MSET(q,w) memset(q, w, sizeof(q))
#define MAX 11234
#define P 100000007
/* fine P 112345678 */

typedef long long ll;

ll fat(ll n){
	if(n == 0LL) return 1LL;
	return n * fat(n - 1LL) % P;
}

ll expbin(ll a, ll b){
	ll y;
	if(b==0) return 1;
	if(b&1) return a * expbin(a, b-1) % P;
	y = expbin(a, b >> 1);
	return y*y % P;
}

int main(void){	
	char str[MAX];
	int oc[26], i;
	ll num, den;
	while(fgets(str, MAX, stdin), strcmp(str,"0\n")){
		num = fat(strlen(str) - 1);
		MSET(oc, 0);
		for(i = 0; str[i] != '\n'; i++) 
			oc[str[i] - 'a']++;
		den = 1LL;
		for(i = 0; i < 26; i++)
			den = den * fat(oc[i]) % P;
		printf("%lld\n", num * expbin(den, P - 2) % P);
	}
	return 0;
}
