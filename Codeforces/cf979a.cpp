/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/contest/979/problem/A
*/

#include <stdio.h>

typedef long long ll;

int main(){
    ll n;
    while(scanf("%lld", &n) != EOF){
        n++;
        printf("%lld\n", (n <= 2) ? n - 1 : n&1LL ? n : n/2LL);
    }
    return 0;
}
