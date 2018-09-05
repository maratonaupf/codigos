/*
 * Leonardo Deliyannis Constantin
 * URI 2091 - Número Solitário
*/

#include <stdio.h>
typedef long long ll;

int main(){
    int N;
    ll A, ans;
    while(scanf("%d", &N), N){
        ans = 0LL;
        while(N--){
            scanf("%lld", &A);
            ans ^= A;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
