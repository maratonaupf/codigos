/*
 * Leonardo Deliyannis Constantin
 * URI 2295 - Frota de Táxi
*/

#include <stdio.h>

int main(){
    double a, g, ra, rg;
    while(scanf("%lf %lf %lf %lf", &a, &g, &ra, &rg) != EOF){
        printf("%c\n", (ra/a > rg/g) ? 'A' : 'G');
    }
    return 0;
}
