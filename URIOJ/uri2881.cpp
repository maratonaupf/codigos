/*
 * Leonardo Deliyannis Constantin
 * URI 2881 - Festival
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
#define INF 0x3f3f3f3f

typedef vector<int> vi;

struct show{
    int i, f, o, p;
    show(int i, int f, int o, int p) : i(i), f(f), o(o), p(p) {}
};

bool cmp(const show &a, const show &b){ return a.i < b.i; }

int N, S;
vector<show> shows;
vector<vi> dp;
vi to;

int solve(int s, int vis){
    if(dp[s][vis] != -1) return dp[s][vis];
    if(s == S) return dp[s][vis] = ((vis == (1<<N)-1) ? 0 : -INF);
    return dp[s][vis] = max(solve(s+1, vis), 
        solve(to[s], vis | (1 << shows[s].p)) + shows[s].o);
}

int main(){
    int M, i, j, f, o, p, ans;
    while(scanf("%d", &N) != EOF){
        shows.clear();
        for(p = 0; p < N; p++){
            scanf("%d", &M);
            while(M--){
                scanf("%d %d %d", &i, &f, &o);
                shows.push_back({i, f, o, p});
            }
        }
        sort(shows.begin(), shows.end(), cmp);
        S = (int)shows.size();
        to.assign(S, S);
        for(i = 0; i < S; i++){
            for(j = i+1; j < S; j++){
                if(shows[i].f <= shows[j].i){
                    to[i] = j;
                    break;
                }
            }
        }
        dp.assign(S+1, vi(1<<N, -1));
        ans = solve(0, 0);
        printf("%d\n", ans > 0 ? ans : -1);
    }
    return 0;
}
