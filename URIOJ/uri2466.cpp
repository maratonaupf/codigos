/*
 * Leonardo Deliyannis Constantin
 * URI 2466 - Sinuca
*/

#include <stdio.h>
#define MAX 64

int main(){
    int N, i, j, last;
    int v[2][MAX];
    while(scanf("%d", &N) != EOF){
        for(i = 0; i < N; i++){
            scanf("%d", &v[0][i]);
            last = v[0][i];
        }
        for(i = 1; i < N; i++){
            for(j = 0; j < N-i; j++){
                last = v[i&1][j] = (v[!(i&1)][j] == v[!(i&1)][j+1] ? 1 : -1);
            }
        }
        printf("%s\n", last == 1 ? "preta" : "branca");
    }
    return 0;
}
