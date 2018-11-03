/*
 * Leonardo Deliyannis Constantin
 * codeforces.com/contest/1073/problem/A
*/

#include <stdio.h>
#include <string.h>
#define LEN 1123

int main(){
    int n, sz, st, i, cnt[26];
    char s[LEN];
    bool diverse, ans;
    while(scanf("%d %s", &n, s) != EOF){
        ans = false;
        for(sz = 2; sz <= n && !ans; sz++){
            for(st = 0; st <= n-sz && !ans; st++){
                diverse = true;
                memset(cnt, 0, sizeof(cnt));
                for(i = st; i < st+sz; i++){
                    if(++cnt[s[i]-'a'] > (int)((double)sz/2.0 + 0.5))
                        diverse = false;
                }
                if(diverse){
                    s[st+sz] = '\0';
                    ans = true;
                    break;
                }
            }
        }
        printf("%s\n", ans ? "YES" : "NO");
        if(ans)
            printf("%s\n", s+st);
    }
    return 0;
}
