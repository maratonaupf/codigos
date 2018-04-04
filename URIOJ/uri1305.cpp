/*
 * Leonardo Deliyannis Constantin
 * URI 1305 - Arredondamento por Valor de Corte
*/

#include <stdio.h>
#include <math.h>

int main(){
    double num, cutoff, val;
    int ans;
    while(scanf("%lf", &num) != EOF){
        scanf("%lf", &cutoff);
        val = num - trunc(num);
        ans = (int)(val > cutoff ? ceil(num) : floor(num));
        printf("%d\n", ans);
    }
    return 0;
}
