/*
 * Leonardo Deliyannis Constantin
 * URI 1620 - Triangulação de Delaunay
*/

#include <stdio.h>

double delaunay(double n){
    return (n-3.0)/n;
}

int main(){
    double n;
    while(scanf("%lf", &n), n){
        printf("%.6lf\n", delaunay(n));
    }
    return 0;
}
