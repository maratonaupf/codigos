/*
 * Leonardo Deliyannis Constantin
 * URI 2435 - Corrida
*/

#include <stdio.h>

int main(){
    int n1, n2, d1, d2, v1, v2;
    while(scanf("%d %d %d", &n1, &d1, &v1) != EOF){
        scanf("%d %d %d", &n2, &d2, &v2);
        double t1 = (double)d1/(double)v1;
        double t2 = (double)d2/(double)v2;
        printf("%d\n", (t1 < t2) ? n1 : n2);
    }
    return 0;
}
