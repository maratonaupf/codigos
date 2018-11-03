/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/problemset/problem/69/A
*/

#include <stdio.h>

int main(){
    int n, i;
    int x, y, z;
    int sx, sy, sz;
    while(scanf("%d", &n) != EOF){
        sx = 0;
        sy = 0;
        sz = 0;
        for(i = 0; i < n; i++){
            scanf("%d %d %d", &x, &y, &z);
            sx += x;
            sy += y;
            sz += z;
        }
        printf("%s\n", (sx == 0 && sy == 0 && sz == 0) ? "YES" : "NO");
    }
    return 0;
}
