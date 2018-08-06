/*
 * Leonardo Deliyannis Constantin
 * URI 2322 - Peça Perdida
*/

#include <stdio.h>
#include <string.h>
#define MAX 1123

int main(){
    int N, i, x;
    bool v[MAX];
    while(scanf("%d", &N) != EOF){
        memset(v, 0, sizeof(v));
        for(i = 1; i < N; i++){
            scanf("%d", &x);
            v[x] = 1;
        }
        for(i = 1; i <= N; i++){
            if(!v[i]){
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}
