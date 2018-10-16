/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/problemset/problem/236/A
*/

#include <stdio.h>
#include <string.h>

int main(){
    int cnt[26], i, ans;
    char s[112];
    while(scanf("%s ", s) != EOF){
        ans = 0;
        memset(cnt, 0, sizeof cnt);
        for(i = 0; s[i]; i++){
            if(++cnt[s[i]-'a'] == 1)
                ans++;
        }
        printf("%s\n", ans&1 ? "IGNORE HIM!" : "CHAT WITH HER!");
    }
    return 0;
}
