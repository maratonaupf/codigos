/*
 * Leonardo Deliyannis Constantin
 * URI 2600 - Tustin e Seu Dado Mágico
*/

#include <stdio.h>
#include <string.h>

int main(){
    int N, i, d[6], cnt[7];
    int op[] = {5, 3, 4};
    bool ans;
    scanf("%d", &N);
    while(N--){
        memset(cnt, 0, sizeof cnt);
        for(i = 0; i < 6; i++){
            scanf("%d", d+i);
            if(1 <= d[i] && d[i] <= 6)
                cnt[d[i]]++;
        }
        ans = true;
        for(i = 1; i <= 6 && ans; i++)
            if(cnt[i] != 1)
                ans = false;
        for(i = 0; i < 3 && ans; i++)
            if(d[i] + d[op[i]] != 7)
                ans = false;
        printf("%s\n", ans ? "SIM" : "NAO");
    }
    return 0;
}
