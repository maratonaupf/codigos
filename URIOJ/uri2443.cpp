/*
 * Leonardo Deliyannis Constantin
 * URI 2443 - Soma de Frações
*/

#include <stdio.h>

int gcd(int a, int b){
    return (b == 0) ? a : gcd(b, a%b);
}

int lcm(int a, int b){
    return (a*b) / gcd(a, b);
}

int main(){
    int a, b, c, d, e, f, g;
    while(scanf("%d %d %d %d", &a, &b, &c, &d) != EOF){
        a *= d;
        b *= d;
        c *= b / d;
        d *= b / d;
        e = a+c;
        f = b;
        g = gcd(e, f);
        e /= g;
        f /= g;
        printf("%d %d\n", e, f);
    }
    return 0;
}
