/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/problemset/problem/116/A
*/

#include <stdio.h>

int main(){
    int n, a, b, ans, cur;
    while(scanf("%d", &n) != EOF){
        ans = cur = 0;
        while(n--){
            scanf("%d %d", &a, &b);
            cur += b - a;
            if(cur > ans)
                ans = cur;
        }
        printf("%d\n", ans);
    }
    return 0;
}
