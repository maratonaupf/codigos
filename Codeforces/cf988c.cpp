/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/contest/988/problem/C
*/ 

#include <stdio.h>
#include <map>
#include <set>
#include <vector>
using namespace std;
#define MAX 212345

typedef pair<int, int> ii;
typedef vector<ii> vii;

int main(){
    int K, i, sz, j, a[MAX], sum, cur;
    pair<ii, ii> ans;
    while(scanf("%d", &K) != EOF){
        map<int, vii> mp;
        ans.first.first = -1;
        for(i = 1; i <= K; i++){
            scanf("%d", &sz);
            sum = 0;
            for(j = 1; j <= sz; j++){
                scanf("%d", &a[j]);
                sum += a[j];
            }
            set<int> st;
            for(j = 1; ans.first.first == -1 && j <= sz; j++){
                if(!st.count(a[j])){
                    st.insert(a[j]);
                    cur = sum-a[j];
                    mp[cur].push_back({i, j});
                    if(mp[cur].size() > 1
                    && mp[cur][0].first != mp[cur][1].first){
                        ans.first = mp[cur][0],
                        ans.second = mp[cur][1];
                    }
                }
            }
        }
        if(ans.first.first != -1){
            printf("YES\n");
            printf("%d %d\n", ans.first.first, ans.first.second);
            printf("%d %d\n", ans.second.first, ans.second.second);
        }
        else printf("NO\n");
    }
    return 0;
}
