/*
 * Leonardo Deliyannis Constantin
 * URI 2840 - Balão++
*/

#include <stdio.h>
#include <math.h>

const double pi = 3.1415;

int main(){
    double v;
    int R, L;
    while(scanf("%d %d", &R, &L) != EOF){
        v = (4.0/3.0) * (pi*pow(R, 3));
        printf("%d\n", (int)floor((double)L/v));
    }
    return 0;
}
