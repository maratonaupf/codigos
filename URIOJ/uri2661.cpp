/*
 * Leonardo Deliyannis Constantin
 * Maratona de Programação SBC 2017
 * D - Despojados
 */

#include <stdio.h>

typedef long long ll;

bool isPrime(ll N){
	for(ll p = 2; p*p <= N; p++)
		if(N % p == 0) return false;
	return true;
}

bool ehDesp(ll N){
	ll PF = 2, cnt = 0;
	while(N != 1 && (PF*PF <= N)){
		if(N % PF == 0){
			ll D2 = N / PF;
			if(D2 != PF && isPrime(D2)){
				N /= D2;
				cnt++;
			}
			N /= PF;
			cnt++;
		}
		while(!isPrime(++PF));
	}
	return N == 1LL && cnt >= 2LL;
}

ll divDesp(ll N){
	ll cont = 0;
	for(ll i = 1; i*i <= N; i++){
		if(N % i == 0){
			if(ehDesp(i)) cont++;
			if(ehDesp(N/i) && (N/i != i)) cont++;
		}
	}
	return cont;
}

int main(){
	ll N;
	while(scanf("%lld", &N) != EOF){
		printf("%lld\n", divDesp(N));
	}
	return 0;
}
