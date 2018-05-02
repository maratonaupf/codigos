/*
 * Leonardo Deliyannis Constantin
 * CodeForces 967 A - Mind The Gap
*/

#include <stdio.h>

int main(){
    int n, s, i, h, m, pt, ct, ans;
    while(scanf("%d %d", &n, &s) != EOF){
        ans = -1;
        pt = -s -1;
        for(i = 0; i < n; i++){
            scanf("%d %d", &h, &m);
            ct = h * 60 + m;
            if(ct - pt >= (s*2 + 2) && ans == -1){
                ans = pt + s + 1;
            }
            pt = ct;
        }
        if(ans == -1)
            ans = ct + s + 1;
        printf("%d %d\n", ans / 60, ans % 60);
    }
    return 0;
}
