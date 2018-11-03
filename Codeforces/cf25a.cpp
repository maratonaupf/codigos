/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/problemset/problem/25/A
*/

#include <stdio.h>

int main(){
    int n, i, a[112], cnt[2], p, idx;
    while(scanf("%d", &n) != EOF){
        cnt[0] = cnt[1] = 0;
        for(i = 1; i <= n; i++){
            scanf("%d", a+i);
            a[i] &= 1;
            cnt[a[i]]++;
        }
        p = (cnt[0] == 1) ? 0 : 1;
        idx = -1;
        for(i = 1; i <= n && idx == -1; i++)
            if(a[i] == p)
                idx = i;
        printf("%d\n", idx);
    }
    return 0;
}
