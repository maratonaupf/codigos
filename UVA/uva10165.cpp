/*
 * Leonardo Deliyannis Constantin
 * UVa 10165 - Stone Game
*/

#include <stdio.h>

int main(){
    int N, i, ans, p;
    while(scanf("%d", &N), N != 0){
        scanf("%d", &ans);
        for(i = 1; i < N; i++){
            scanf("%d", &p);
            ans ^= p;
        }
        printf("%s\n", ans != 0 ? "Yes" : "No");
    }
    return 0;
}
