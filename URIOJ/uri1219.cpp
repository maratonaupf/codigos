/*
 * Leonardo Deliyannis Constantin
 * URI 1219 - Flores Coloridas
*/

#include <stdio.h>
#include <math.h>
#define PI acos(-1.0)

int main(){
    int a, b, c;
    double S, V, R, at, p, rr, rs;
    while(scanf("%d %d %d", &a, &b, &c) != EOF){
        p = (a + b + c) / 2.0;
        at = sqrt(p * (p-a) * (p-b) * (p-c));
        rr = at / p;
        R = PI * rr * rr;
        V = at - R;
        rs = (a*b*c) / (4*at);
        S = PI * rs * rs - at;
        printf("%.4lf %.4lf %.4lf\n", S, V, R);
    }
    return 0;
}
