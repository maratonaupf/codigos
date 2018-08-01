/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/contest/1015/problem/A
*/

#include <stdio.h>
#include <string.h>
#define MAX 112

int main(){
    int N, M, a, b, i, ans;
    bool p[MAX];
    while(scanf("%d %d", &N, &M) != EOF){
        memset(p, 0, sizeof(p));
        ans = M;
        while(N--){
            scanf("%d %d", &a, &b);
            for(i = a; i <= b; i++){
                if(p[i] == 0)
                    ans--;
                p[i] = 1;
            }
        }
        printf("%d\n", ans);
        for(i = 1; i <= M; i++){
            if(!p[i]) 
                printf("%d%c", i, --ans > 0 ? ' ' : '\n');
        }
    }
    return 0;
}
