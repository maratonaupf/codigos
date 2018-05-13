/*
 * Leonardo Deliyannis Constantin
 * URI 2393 - O Mar não está para Peixe
*/

#include <stdio.h>
#include <string.h>
#define MAX 112

bool grid[MAX][MAX];

int main(){
    int N, xi, xf, yi, yf;
    int x, y, ans;
    while(scanf("%d", &N) != EOF){
        memset(grid, 0, sizeof(grid));
        ans = 0;
        while(N--){
            scanf("%d %d %d %d", &xi, &xf, &yi, &yf);
            for(x = xi; x < xf; x++)
                for(y = yi; y < yf; y++)
                    if(!grid[x][y]){
                        grid[x][y] = 1;
                        ans++;
                    }
        }
        printf("%d\n", ans);
    }
    return 0;
}
