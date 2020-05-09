/*
 * Leonardo Deliyannis Constantin
 * Google Code Jam 2020, Round 1A - Pascal Walk
*/

#include<bits/stdc++.h>
using namespace std;
#define INF 0x3F3F3F3F

typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<vll> p;

void gen(int lines){
    ll i, j;
    p.assign(lines+1, vll());
    for(i = 1; i <= lines; i++){
        for(j = 0; j <= i; j++){
            if(j == 0){
                p[i].push_back(0);
                continue;
            }
            else if(j == 1 || j == i)
                p[i].push_back(1);
            else
                p[i].push_back((ll) p[i-1][j-1] + (ll) p[i-1][j]);
        }
    }
}

const int di[] = {-1, -1,  0,  0,  1,  1};
const int dj[] = {-1,  0, -1,  1,  0,  1};

bool isValid(int i, int j){
    return (1 <= i && i < (int)p.size() && 1 <= j && j < (int)p.size());
}

vii bfs(int si, int sj, int n){
    vector<vll> dist(p.size(), vll(p.size(), INF));
    dist[si][sj] = 0;
    queue<ii> q;
    q.push({si, sj});
    while(!q.empty()){
        ll
    }
}

int main(){
    int t, tc, n;
    scanf("%d", &t);
    gen(31);
    for(tc = 1; tc <= t; tc++){
        scanf("%d", &n);
        printf("Case #%d:\n", tc);
        vii ans = bfs(1, 1, n);
        for(auto a : ans){
            printf("%d %d\n", a.first, a.second);
        }
    }
    return 0;
}
