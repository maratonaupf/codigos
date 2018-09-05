/*
 * Leonardo Deliyannis Constantin
 * URI 1539 - Empresa de Telecom
*/

#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
#define INF (1e9)

typedef vector<int> vi;
typedef vector<double> vd;

struct pt{
    int x, y, r;
    pt(){ x = y = r = 0; }
    pt(int x, int y, int r): x(x), y(y), r(r) {}
};

void floydWarshall(vector<vd> &AG){
    int n = (int)AG.size();
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                AG[i][j] = min(AG[i][j], AG[i][k]+AG[k][j]);
}

int main(){
    int N, Q, x, y, r;
    while(scanf("%d", &N), N){
        vector<pt> v;
        vector<vd> AG(N, vd(N, INF));
        for(int i = 0; i < N; i++){
            scanf("%d %d %d", &x, &y, &r);
            v.push_back({x, y, r});
        }
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++){
                double dist = hypot(v[i].x- v[j].x, v[i].y - v[j].y);
                if(dist <= (double)v[i].r)
                    AG[i][j] = dist;
            }
        floydWarshall(AG);
        scanf("%d", &Q);
        while(Q--){
            scanf("%d %d", &x, &y);
            x--, y--;
            printf("%d\n", (AG[x][y] < INF) ? (int)AG[x][y] : -1);
        }
    }
    return 0;
}
