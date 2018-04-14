/*
 * Leonardo Deliyannis Constantin
 * URI 1901 - Borboletas
*/

#include <stdio.h>
#include <set>
using namespace std;
#define MAX 212

int main(){
    int N, i, j, k;
    int grid[MAX][MAX];
    while(scanf("%d", &N) != EOF){
        for(i = 0; i < N; i++)
            for(j = 0; j < N; j++)
                scanf("%d", &grid[i][j]);
        set<int> myset;
        for(k = 0; k < N*2; k++){
            scanf("%d %d", &i, &j);
            i--; j--;
            myset.insert(grid[i][j]);
        }
        printf("%d\n", (int)myset.size());
    }
    return 0;
}
