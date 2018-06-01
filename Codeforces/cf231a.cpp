// Leonardo Deliyannis Constantin
// http://codeforces.com/problemset/problem/231/A

#include <stdio.h>

int main(){
    int n, cnt, i, a, ans;
    while(scanf("%d", &n) != EOF){
        ans = 0;
        while(n--){
            cnt = 0;
            for(i = 0; i < 3; i++){
                scanf("%d", &a);
                cnt += a;
            }
            ans += cnt >= 2;
        }
        printf("%d\n", ans);
    }
    return 0;
}
