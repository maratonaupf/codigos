/*
 * Leonardo Deliyannis Constantin
 * URI 2088 - Combate à Dengue
*/

#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 16
#define INF (2e9)

typedef vector<double> vd;

int N;
vector<vd> dist, memo;

double tsp(int pos, int bitmask){
    if(bitmask == (1 << (N+1)) - 1)
        return dist[pos][0];
    if(memo[pos][bitmask] != -1)
        return memo[pos][bitmask];
    double ans = INF;
    for(int nxt = 0; nxt <= N; nxt++){
        if(nxt != pos && !(bitmask & (1 << nxt)))
            ans = min(ans, dist[pos][nxt] + tsp(nxt, bitmask | (1 << nxt)));
    }
    return memo[pos][bitmask] = ans;
}

int main(){
    int x[MAX], y[MAX], i, j;
    while(scanf("%d", &N) != EOF && N != 0){
        dist.assign(N+1, vd(N+1, INF));
        memo.assign(N+1, vd(1 << (N+1), -1));
        for(i = 0; i <= N; i++){
            scanf("%d %d", x+i, y+i);
            for(j = 0; j <= i; j++)
                dist[i][j] = dist[j][i] = hypot(x[j]-x[i], y[j]-y[i]);
        }
        printf("%.2lf\n", tsp(0, 1));
    }
    return 0;
}
