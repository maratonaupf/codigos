/*
 * Leonardo Deliyannis Constantin
 * URI 2449 - Fechadura
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 1123

int main(){
    int N, M, i, a[MAX];
    int ans, dif;
    while(scanf("%d %d", &N, &M) != EOF){
        for(i = 0; i < N; i++){
            scanf("%d\n", &a[i]);
        }
        ans = 0;
        for(i = 0; i < N-1; i++){
            dif = M - a[i];
            a[i]   += dif;
            a[i+1] += dif;
            ans += abs(dif);
        }
        printf("%d\n", ans);
    }
    return 0;
}
