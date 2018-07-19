/*
 * Leonardo Deliyannis Constantin
 * URI 2828 - Anagramas
*/

#include <stdio.h>
#include <string.h>
#define LEN 112345
#define P (((int)1e9) + 7)

typedef long long ll;

ll expmod(ll b, ll e, ll mod){
    if(e == 0) return 1;
    if(e&1) return (b * expmod(b, e-1, mod)) % mod;
    ll aux = expmod(b, e >> 1, mod);
    return (aux*aux) % mod;
}

ll facMod(ll n, ll mod){
    ll ans, i;
    for(i = ans = 1; i <= n; i++){
        ans *= i;
        ans %= mod;
    }
    return ans;
}

ll anagrams(const char *s){
    ll n, i, num, den;
    ll freq[26];
    memset(freq, 0, sizeof(freq));
    for(n = 0; s[n]; n++){
        freq[s[n] - 'a']++;
    }
    num = facMod(n, P);
    den = 1;
    for(i = 0; i < 26; i++)
        den = ((den % P) * facMod(freq[i], P)) % P;
    return ((num % P) * (expmod(den, P-2, P) % P)) % P;
}

int main(){
    char s[LEN];
    while(scanf("%s", s) != EOF){
        printf("%lld\n", anagrams(s));
    }
    return 0;
}
