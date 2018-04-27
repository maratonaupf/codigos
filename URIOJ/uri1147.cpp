/*
 * Leonardo Deliyannis Constantin
 * URI 1147 - Fuga do Cavalo
*/

#include <stdio.h>
#include <string.h>
#define MAX 8

int isValid(int i, int j){
    return 0 <= i && i < MAX && 0 <= j && j < MAX;
}

int main(){
    int tc = 0;
    int i, j, k, si, sj, pi, pj;
    char s[4];
    char p[4];
    int grid[MAX][MAX];
    int ans;
    const int di[] = { -2, -2, -1, -1,  1,  1,  2,  2 };
    const int dj[] = { -1,  1, -2,  2, -2,  2, -1,  1 };
    while(fgets(s, 4, stdin), s[0] != '0'){
        si = s[0] - '1';
        sj = s[1] - 'a';
        memset(grid, 0, sizeof(grid));
        for(i = 0; i < 8; i++){
            fgets(p, 4, stdin);
            pi = p[0] - '1';
            pj = p[1] - 'a';
            if(isValid(pi-1, pj-1))
                grid[pi-1][pj-1] = 1;
            if(isValid(pi-1, pj+1))
                grid[pi-1][pj+1] = 1;
        }
        ans = 0;
        for(k = 0; k < 8; k++){
            i = si+di[k];
            j = sj+dj[k];
            if(isValid(i, j) && grid[i][j] == 0)
                ans++;
        }
        printf("Caso de Teste #%d: %d movimento(s).\n", ++tc, ans);
    }
    return 0;
}
