/*
 * Leonardo Deliyannis Constantin
 * URI 2516 - Corrida
*/

#include <stdio.h>

int main(){
    int s, va, vb;
    while(scanf("%d %d %d", &s, &va, &vb) != EOF){
        if(va <= vb)
            printf("impossivel\n");
        else
            printf("%.2lf\n", (double)s/(double)(va-vb));
    }
    return 0;
}
