/*
 * Leonardo Deliyannis Constantin
 * URI 2779 - Álbum da Copa
*/

#include <stdio.h>
#include <string.h>
#define MAX 112

int main(){
    int N, M, x;
    bool album[MAX];
    while(scanf("%d", &N) != EOF){
        memset(album, 0, sizeof(album));
        scanf("%d", &M);
        while(M--){
            scanf("%d", &x);
            if(!album[x]){
                album[x] = true;
                N--;
            }
        }
        printf("%d\n", N);
    }    
    return 0;
}
