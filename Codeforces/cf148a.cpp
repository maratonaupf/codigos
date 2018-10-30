/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/problemset/problem/148/A
*/

#include <stdio.h>
#include <string.h>
#define MAX 112345

int main(){
    int j, k[4], i, d, cnt;
    bool dmg[MAX];
    while(scanf("%d", &k[0]) != EOF){
        for(j = 1; j < 4; j++)
            scanf("%d", &k[j]);
        memset(dmg, 0, sizeof(dmg));
        cnt = 0;
        scanf("%d", &d);
        for(j = 0; j < 4; j++){
            for(i = k[j]; i <= d; i += k[j]){
                if(dmg[i] == 0){
                    dmg[i] = 1;
                    cnt++;
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
