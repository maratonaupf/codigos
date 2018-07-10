/*
 * Leonardo Deliyannis Constantin
 * URI 2343 - Caçadores de Mitos
*/

#include <stdio.h>
#include <string.h>
#define MAX 512

int main(){
    int N, x, y, ans;
    char grid[MAX][MAX];
    while(scanf("%d", &N) != EOF){
        memset(grid, 0, sizeof grid);
        ans = 0;
        while(N--){
            scanf("%d %d", &x, &y);
            ans |= (int)grid[x][y];
            grid[x][y] = 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
