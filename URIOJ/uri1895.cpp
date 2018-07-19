/*
 * Leonardo Deliyannis Constantin
 * URI 1895 - Jogo do Limite 
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int N, T, L, S, i, dif, v[2];
    while(scanf("%d %d %d", &N, &T, &L) != EOF){
        v[0] = v[1] = 0;
        for(i = 0; i < N-1; i++){
            scanf("%d", &S);
            dif = abs(T-S);
            if(dif <= L){
                T = S;
                v[i&1] += dif;
            }
        }
        printf("%d %d\n", v[0], v[1]);
    }
    return 0;
}
