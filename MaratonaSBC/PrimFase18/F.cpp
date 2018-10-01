/*
 * Leonardo Deliyannis Constantin
 * Maratona SBC 2018 - Festival
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f

typedef vector<int> vi;

struct show{
    int ini, fin, mus, pal;
    show(){ ini = fin = mus = pal = 0; }
    show(int i, int f, int m, int p) : ini(i), fin(f), mus(m), pal(p) {}
};

bool cmp(const show &a, const show &b){
    return a.ini < b.ini;
}

int P, N;
vector<show> v;
vector<vi> dp;
vi to;

int solve(int s, int vis){
    if(s == N) return ((vis == (1<<P) - 1) ? 0 : -INF);
    if(dp[s][vis] != -1) return dp[s][vis];
    return dp[s][vis] = max(solve(s+1, vis),
        solve(to[s], vis | v[s].pal) + v[s].mus);
}

int main(){
    int m, i, j, f, o;
    while(scanf("%d", &P) != EOF){
        v.clear();
        for(int p = 0; p < P; p++){
            scanf("%d", &m);
            while(m--){
                scanf("%d %d %d", &i, &f, &o);
                v.push_back({i, f, o, 1<<p});
            }
        }
        sort(v.begin(), v.end(), cmp);
        N = (int)v.size();
        to.assign(N+1, N);
        for(i = 0; i < N; i++){
            for(j = i+1; j < N && to[i] == N; j++)
                if(v[i].fin <= v[j].ini)
                    to[i] = j;
        }
        dp.assign(N+1, vi(1 << P, -1));
        int ans = solve(0, 0);
        printf("%d\n", ans > 0 ? ans : -1);
    }
    return 0;
}
