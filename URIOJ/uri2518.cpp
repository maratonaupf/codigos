/*
 * Leonardo Deliyannis Constantin
 * URI 2518 - Escada do DINF
*/

#include <stdio.h>
#include <math.h>

int main(){
    double N, H, C, L;
    double ans;
    while(scanf("%lf", &N) != EOF){
        scanf("%lf %lf %lf", &H, &C, &L);
        ans = hypot(H, C) * L * N;
        printf("%.4lf\n", ans / 10000.0);
    }
    return 0;
}
