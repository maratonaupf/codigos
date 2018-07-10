/*
 * Leonardo Deliyannis Constantin
 * URI 2808 - Mais Cavalos
*/ 

#include <stdio.h>
#include <string.h>
#define MAX 8

int grid[MAX][MAX];
const int di[] = { -2, -2, -1, -1,  1,  1,  2,  2 };
const int dj[] = { -1,  1, -2,  2, -2,  2, -1,  1 };

int isValid(int i, int j){
    return 0 <= i && i < MAX && 0 <= j && j < MAX;
}

int main(){
    int si, sj, ti, tj, k, i2, j2;
    char o[4], d[4];
    while(scanf("%s %s", o, d) != EOF){
        si = o[0] - 'a';
        sj = o[1] - '1';
        ti = d[0] - 'a';
        tj = d[1] - '1';
        memset(grid, 0, sizeof(grid));
        for(k = 0; k < 8; k++){
            i2 = si+di[k], j2 = sj+dj[k];
            if(isValid(i2, j2))
                grid[i2][j2] = 1;
        }
        printf("%sVALIDO\n", isValid(ti, tj) && grid[ti][tj] ? "" : "IN");
    }
    return 0;
}
