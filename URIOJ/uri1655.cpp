/*
 * Leonardo Deliyannis Constantin
 * URI 1655 - 106 Milhas Para Chicago
*/

#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 112

typedef vector<double> vd;

int n, m;
vector<vd> AG;

void floydWarshall(){
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                AG[i][j] = max(AG[i][j], AG[i][k] * AG[k][j]);
}

int main(){
    int x, y, p;
    while(scanf("%d", &n), n){
        scanf("%d", &m);
        AG.assign(n, vd(n, 0.0));
        while(m--){
            scanf("%d %d %d", &x, &y, &p);
            x--, y--;
            AG[x][y] = AG[y][x] = 0.01 * (double)p;
        }
        floydWarshall();
        printf("%.6lf percent\n", AG[0][n-1]*100.0);
    }
    return 0;
}
