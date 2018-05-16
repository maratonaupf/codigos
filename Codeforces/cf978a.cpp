/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/contest/978/problem/A
*/

#include <stdio.h>
#include <string.h>
#define MAX 51

int main(){
    int N, i, a[MAX];
    int ans[MAX], sz;
    bool exist[1123];
    while(scanf("%d", &N) != EOF){
        for(i = 0; i < N; i++){
            scanf("%d", a+i);
        }
        memset(exist, false, sizeof(exist));
        sz = 0;
        for(i = N-1; i >= 0; i--){
            if(!exist[a[i]]){
                exist[a[i]] = true;
                ans[sz++] = a[i];
            }
        }
        printf("%d\n", sz);
        while(sz--){
            printf("%d%c", ans[sz], (sz > 0) ? ' ' : '\n');
        }
    }
    return 0;
}
