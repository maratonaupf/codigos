/*
 * Leonardo Deliyannis Constantin
 * URI 2451 - PacMan
*/

#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 112

int main(){
    int N, i, j, cur, ans;
    int start, end, step;
    char grid[MAX][MAX];
    while(scanf("%d", &N) != EOF){
        ans = cur = 0;
        for(i = 0; i < N; i++){
            scanf(" %s", grid[i]);
            start = (i&1) ? N-1 : 0;
            end   = (i&1) ?  -1 : N;
            step  = (i&1) ?  -1 : 1;
            for(j = start; j != end; j += step){
                if(grid[i][j] == 'o')
                    cur++;
                if(grid[i][j] == 'A')
                    cur = 0;
                ans = max(cur, ans);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
