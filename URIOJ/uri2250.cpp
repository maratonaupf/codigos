/*
 * Leonardo Deliyannis Constantin
 * URI 2250 - Tetris
*/

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define LEN 32
#define INF (int)(1e9)

typedef pair<int, string> player;

bool cmp(const player &a, const player &b){
    if(a.first != b.first){
        return a.first > b.first;
    }
    return a.second < b.second;
}

int main(){
    int tc = 0, J, i, idx;
    int lo, hi, pts, tot;
    char s[LEN];
    while(scanf("%d ", &J), J != 0){
        vector<player> v;
        while(J--){
            scanf("%s", s);
            lo =  INF;
            hi = -INF;
            tot = 0;
            for(i = 0; i < 12; i++){
                scanf("%d", &pts);
                lo = min(lo, pts);
                hi = max(hi, pts);
                tot += pts;
            }
            tot -= lo + hi;
            v.push_back({tot, s});
        }
        sort(v.begin(), v.end(), cmp);
        printf("Teste %d\n", ++tc);
        for(i = 0; i < (int)v.size(); i++){
            idx = (i == 0 || v[i-1].first != v[i].first) ? i : idx;
            printf("%d %d %s\n", idx+1, v[i].first, v[i].second.c_str());
        }
        printf("\n");
    }
    return 0;
}
