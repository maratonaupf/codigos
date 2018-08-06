/*
 * Leonardo Deliyannis Constantin
 * URI 2217 - Nove
*/

#include <stdio.h>

int main(){
    int T, N;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        printf("%d\n", (N&1) ? 9 : 1);
    }
    return 0;
}
