#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef long long ll;

ll expbin(ll a, ll b){
	if(b == 0) return 1;
	if(b == 1) return a;
	return(b&1) ? 
		a * expbin(a*a, b>>1) :
		expbin(a*a, b>>1);
}

int main(void){
	ll N;
	while(scanf("%lld", &N) != EOF)
		printf("%lld\n", expbin(3, N));
	return 0;
}
