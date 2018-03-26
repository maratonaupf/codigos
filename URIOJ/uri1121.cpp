/*
 * Leonardo Deliyannis Constantin
 * URI 1121 - Robô Colecionador
*/

#include <stdio.h>
#include <ctype.h>
#define MAX 112
#define LEN 51234

int N, M, S;
char grid[MAX][MAX];
char s[LEN];
const char d[] = "NLSO";
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};

bool isValid(int i, int j){
    return 0 <= i && i < N && 0 <= j && j < M && grid[i][j] != '#';
}

int traverse(int i, int j, int face){
    int cnt = 0;
    for(int c = 0; s[c] != '\n'; c++){
        if(s[c] == 'F'){
            int i2 = i+di[face],
                j2 = j+dj[face];
            if(isValid(i2, j2)){
                i = i2;
                j = j2;
                if(grid[i][j] == '*'){
                    grid[i][j] = '.';
                    cnt++;
                }
            }
        }
        if(s[c] == 'E'){ face = (face - 1 + 4) % 4; }
        if(s[c] == 'D'){ face = (face + 1) % 4; }
    }
    return cnt;
}

int main(){
    int i, j, k, si, sj, face;
	while(scanf("%d %d %d ", &N, &M, &S), N != 0){
        for(i = 0; i < N; i++){
            fgets(grid[i], MAX, stdin);
        }
        fgets(s, LEN, stdin);
        for(i = 0; i < N; i++)
            for(j = 0; j < M; j++)
                if(isalpha(grid[i][j]))
                    for(k = 0; k < 4; k++)
                        if(grid[i][j] == d[k]){
                            si = i;
                            sj = j;
                            face = k;
                            break; 
                        }
        printf("%d\n", traverse(si, sj, face));
    }
	return 0;
}
