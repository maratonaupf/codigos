/*
 * Leonardo Deliyannis Constantin
 * URI 1745 - Counting substhreengs
*/

#include <stdio.h>
#include <ctype.h>
#define MAX 1123456

typedef long long ll;

int main(){
    char s[MAX];
    int i, acum;
    ll ans, cnt[3];
    while(fgets(s, MAX, stdin)){
        cnt[0] = 1;
        cnt[1] = cnt[2] = ans = 0LL;
        acum = 0;
        for(i = 0; s[i+1]; i++){
            if(!isdigit(s[i])){
                cnt[0] = 0;
                acum = 0;
                cnt[1] = cnt[2] = 0LL;
            }
            acum = (acum + s[i] - '0') % 3;
            ans += cnt[acum];
            cnt[acum]++;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
