/*
 * Leonardo Deliyannis Constantin
 * URI 2636 - 3-RSA
 */

#include <stdio.h>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

bool isPrime(ll N){
	if(N < 2) return false;
	for(ll i = 2; i*i <= N; i++)
		if(N%i == 0) return false;
	return true;
}

vll primeFactors(ll N){
	vll fac;
	ll PF = 2;
	while(N != 1 && (PF*PF <= N)){
		while(N % PF == 0){
			N /= PF;
			fac.push_back(PF);
		}
		PF++;
	}
	if(N != 1) fac.push_back(N);
	return fac;
}

int main(){
	ll n;
	while(scanf("%lld", &n), n != 0){
		vll ans = primeFactors(n);
		printf("%lld = ", n);
		for(int i = 0; i < (int)ans.size(); i++){
			if(i > 0) printf(" x ");
			printf("%lld", ans[i]);
		} printf("\n");
	}
	return 0;
}
