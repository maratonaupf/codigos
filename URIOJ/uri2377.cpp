/*
 * Leonardo Deliyannis Constantin
 * URI 2377 - Pedágio
*/

#include <stdio.h>

int main(){
    int L, D, K, P;
    while(scanf("%d %d", &L, &D) != EOF){
        scanf("%d %d", &K, &P);
        printf("%d\n", L*K + P*(L/D));
    }
    return 0;
}
