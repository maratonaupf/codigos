/*
 * Leonardo Deliyannis Constantin
 * URI 2473 - Loteria
*/

#include <stdio.h>
#include <string.h>
#define MAX 112

int main(){
    int cnt[MAX], ans, x, i;
    char s[4][10] = { "terno", "quadra", "quina", "sena" };
    while(scanf("%d", &x) != EOF){
        memset(cnt, 0, sizeof(cnt));
        for(i = 0; i < 6; i++){
            if(i > 0) scanf("%d", &x);
            cnt[x]++;
        }
        ans = 0;
        for(i = 0; i < 6; i++){
            scanf("%d", &x);
            if(cnt[x]) ans++;
        }
        printf("%s\n", ans >= 3 ? s[ans-3] : "azar");
    }
    return 0;
}
