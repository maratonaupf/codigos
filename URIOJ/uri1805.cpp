#include<stdio.h>
 
typedef long double ld;
typedef long long ll;

/* PAY MORE ATTENTION TO PROBLEM LIMITS!!! 
 * 
 * A and B could go up to 10^9 in this problem, 
 * which could result in quite high numbers, 
 * not suitable for int */

int main(void) {
	ll a, b, n;
	ld m, d;
	while(scanf("%lld %lld", &a, &b) != EOF){
		d = (b-a);
		m = a + (d / 2.0);
		n = d + 1;
		printf("%lld\n", (ll)(m*n));
	}
	return 0;
}
