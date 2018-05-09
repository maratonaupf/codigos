/*
 * Leonardo Deliyannis Constantin
 * URI 1148 - Países em Guerra
*/

#include <stdio.h>
#include <string.h> // memset()
#include <algorithm>
using namespace std;
#define MAX 512
#define INF 0x3c3c3c3c

int N, E;
int AG[MAX][MAX];

void floydWarshall(){
    for(int k = 0; k < N; k++)
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                AG[i][j] = min(AG[i][j], AG[i][k] + AG[k][j]);
}

int main(){
    int x, y, h, k;
    while(scanf("%d %d", &N, &E), N != 0){
        memset(AG, INF, sizeof(AG));
        for(int i = 0; i < E; i++){
            scanf("%d %d %d", &x, &y, &h);
            x--, y--;
            AG[x][y] = h;
            if(AG[x][y] != INF && AG[y][x] != INF)
                AG[x][y] = AG[y][x] = 0;
        }
        floydWarshall();
        scanf("%d", &k);
        while(k--){
            scanf("%d %d", &x, &y);
            x--, y--;
            if(AG[x][y] != INF)
                printf("%d\n", AG[x][y]);
            else
                printf("Nao e possivel entregar a carta\n");
        }
        printf("\n");
    }
    return 0;
}
