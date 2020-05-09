/*
 * Leonardo Deliyannis Constantin
 * 
*/

#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

int n, e;
vvi LG;
vector<ll> h;

ll dfs(int u, int p, ll dep){
    ll siz = 1;
    for(int v : LG[u]){
        if(v != p)
            siz += dfs(v, u, dep+1);
    }
    h.push_back(siz-dep);
    return siz;
}

int main(){
    int k;
    int u, v, i;
    while(scanf("%d %d", &n, &k) != EOF){
        e = n-1;
        LG.assign(n+1, vi());
        for(i = 0; i < e; i++){
            scanf("%d %d", &u, &v);
            LG[u].push_back(v);
            LG[v].push_back(u);
        }
        dfs(1, 1, 1);
        sort(h.begin(), h.end(), greater<ll>());
        ll ans = 0LL;
        for(i = 0; i < n-k; i++){
            ans += h[i];
        }
        printf("%lld\n", ans);
        h.clear();
    }
    return 0;
}
