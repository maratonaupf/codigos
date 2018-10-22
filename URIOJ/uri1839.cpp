/*
 * Leonardo Deliyannis Constantin
 * URI 1839 - A Câmara Secreta
*/

#include <stdio.h>
#define MAX 2523
#define LEN 52

const int MOD = (int)1e9 + 7;

int c[MAX][MAX];

void setup(){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j <= i; j++){
            c[i][j] = (j == 0 || j == i) ? 
                1 : ((c[i-1][j-1] % MOD) + (c[i-1][j] % MOD)) % MOD;
        }
    }
}

char grid[LEN][LEN];

int main(){
    int N, M, i, j, all, black, xa, ya, xb, yb;
    setup();
    scanf("%d %d ", &N, &M);
    for(i = 0; i < N; i++)
        scanf("%s", grid[i]);
    while(scanf("%d %d %d %d ", &xa, &ya, &xb, &yb) != EOF){
        xa--, ya--;
        all = (xb - xa) * (yb - ya);
        xb--, yb--;
        black = 0;
        for(i = xa; i <= xb; i++)
            for(j = ya; j <= yb; j++)
                if(grid[i][j] == '#')
                    black++;
        printf("%d\n", c[all][black]-1);
    }
    return 0;
}
