/*
 * Leonardo Deliyannis Constantin
 * URI 2568 - Ações
*/

#include <stdio.h>

int main(){
    int D, I, X, F;
    while(scanf("%d %d %d %d", &D, &I, &X, &F) != EOF){
        printf("%d\n", I + ((D&1) ? (F&1) ? X : 0 : (F&1) ? -X : 0));
    }
    return 0;
}
