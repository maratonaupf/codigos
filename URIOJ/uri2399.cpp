/*
 * Leonardo Deliyannis Constantin
 * URI 2399 - Campo Minado
*/

#include <stdio.h>
#define MAX 52

int main(){
    int N, i;
    int v[MAX];
    while(scanf("%d", &N) != EOF){
        for(i = 1; i <= N; i++){
            scanf("%d", &v[i]);
        }
        v[0] = v[N+1] = 0;
        for(i = 1; i <= N; i++){
            printf("%d\n", v[i-1] + v[i] + v[i+1]);
        }
    }
    return 0;
}
