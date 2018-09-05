/*
 * Leonardo Deliyannis Constantin
 * URI 2802 - Dividindo Círculos
*/

#include <stdio.h>
#include <math.h>

typedef long long ll;
typedef long double ld;

ll f(ld n){
    return (ll)ceil(n/24.0 * (n*n*n - 6.0*n*n + 23.0*n - 18.0) + 1.0);
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        printf("%lld\n", f(n));
    }
    return 0;
}
