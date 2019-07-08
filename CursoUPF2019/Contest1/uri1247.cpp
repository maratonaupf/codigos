/*
 * Leonardo Deliyannis Constantin
 * Curso de Aperfeiçoamento em Programação Competitiva @ UPF 2019
 * Contest 1 - Problema C 
 * URI 1247 - Guarda Costeira
*/

#include <stdio.h>
#include <math.h>
#define EPS (1e-9)

int cmp(double a, double b){
    return (fabs(a-b) < EPS) ? 0 : (a < b) ? -1 : 1;
}

int main(){
    double d, vf, vg, tf, tg;
    while(scanf("%lf %lf %lf", &d, &vf, &vg) != EOF){
        tf = 12.0 / vf;
        tg = hypot(12.0, d) / vg;
        printf("%c\n", (cmp(tf, tg) >= 0) ? 'S' : 'N');
    }
    return 0;
}
