/*
 * Leonardo Deliyannis Constantin
 * CodeForces 1A - Theatre Square
 */

#include <stdio.h>

typedef long long ll;

int main(){
	ll n, m, a;
	while(scanf("%lld %lld %lld", &n, &m, &a) != EOF){
		if(n%a) n += a - (n%a);
		if(m%a) m += a - (m%a);
		printf("%lld\n", (n*m) / (a*a));
	}
	return 0;
}
