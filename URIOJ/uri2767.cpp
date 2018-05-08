/*
 * Leonardo Deliyannis Constantin
 * URI 2767 - Festa
*/

#include <stdio.h>
#include <string.h>
#define MAX 112345

int main(){
    int N, M, K;
    int i, h;
    int rem[MAX];
    long long ans;
    while(scanf("%d %d %d", &N, &M, &K) != EOF){
        memset(rem, 0, sizeof(rem));
        for(i = 0; i < N; i++){
            scanf("%d", &h);
            rem[h % K]++;
        }
        ans = 0;
        for(i = 0; i < M; i++){
            scanf("%d", &h);
            ans += rem[(K - (h % K))%K];
        }
        printf("%lld\n", ans);
    }
    return 0;
}
