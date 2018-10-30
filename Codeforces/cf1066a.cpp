/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/contest/1066/problem/A
*/

#include <stdio.h>

int main(){
    int t, L, v, l, r, ans;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d %d", &L, &v, &l, &r);
        ans = L/v;
        ans -= r/v - (l-1)/v;
        printf("%d\n", ans);
    }
    return 0;
}
