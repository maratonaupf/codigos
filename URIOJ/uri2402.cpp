/*
 * Leonardo Deliyannis Constantin
 * URI 2402 - Selos
*/

#include <stdio.h>

typedef long long ll;

bool isPrime(ll N){
    for(ll i = 2; i*i <= N; i++)
        if(N % i == 0)
            return false;
    return true;
}

int main(){
    ll N;
    while(scanf("%lld", &N) != EOF){
        printf("%c\n", N < 4 || isPrime(N) ? 'N' : 'S');
    }
    return 0;
}
