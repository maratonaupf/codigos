/*
 * Leonardo Deliyannis Constantin
 * https://codeforces.com/problemset/submission/344/63344493
*/

#include <stdio.h>
#include <string.h>

int main(){
    int n, ans;
    char current[4], last[4];
    while(scanf("%d", &n) != EOF){
        last[0] = '\0';
        ans = 0;
        while(n--){
            scanf(" %s", current);
            if(current[0] != last[0])
                ans++;
            strcpy(last, current);
        }
        printf("%d\n", ans);
    }
    return 0;
}
