/*
 * Leonardo Deliyannis Constantin
 * URI 2156 - As Aventuras de Pak-man
*/

#include <stdio.h>
#define MAX 112
#define LEN 11234

int L, C;
bool isValid(int i, int j){
    return 0 <= i  && i < L && 0 <= j && j < C;
}

int dir(int c){
    return (c == 'U') ? 0 : (c == 'L') ? 1 : (c == 'R') ? 2 : 3;
}

int main(){
    int I, i, j, k, c, si, sj, i2, j2, ans;
    char grid[MAX][MAX], s[LEN];
    const int di[] = { -1,  0,  0,  1 };
    const int dj[] = {  0, -1,  1,  0 };
    while(scanf("%d %d %d ", &L, &C, &I), L){
        si = sj = 0;
        for(i = 0; i < L; i++){
            fgets(grid[i], MAX, stdin);
            for(j = 0; j < C; j++){
                if(grid[i][j] == '<'){
                    si = i; sj = j;
                    grid[i][j] = ' ';
                }
            }
        }
        fgets(s, LEN, stdin);
        k = dir('R');
        ans = 0;
        for(c = 0; c < I; c++){
            if(s[c] == 'W'){
                i2 = si+di[k], j2 = sj+dj[k];
                if(isValid(i2, j2) && grid[i2][j2] != '#'){
                    si = i2, sj = j2;
                    if(grid[si][sj] == '*'){
                        ans++;
                        grid[si][sj] = ' ';
                    }
                }
            }
            else k = dir(s[c]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
