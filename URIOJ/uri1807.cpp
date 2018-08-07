/*
 * Leonardo Deliyannis Constantin
 * URI 1807 - Triângulo Trinomial, a Vingança
*/

#include <stdio.h>

typedef long long ll;
const ll mod = ((1LL << 31LL)-1LL);

ll exp(ll a, ll b){
    if(b == 0LL) return 1LL;
    if(b & 1LL) 
        return ((a%mod) * (exp((a%mod)*(a%mod)%mod, b>>1LL)%mod)) % mod;
    return exp((a%mod)*(a%mod)%mod, b>>1LL)%mod;
}


int main(){
    ll n;
    while(scanf("%lld", &n) != EOF){
        printf("%lld\n", exp(3LL, n));
    }
    return 0;
}
