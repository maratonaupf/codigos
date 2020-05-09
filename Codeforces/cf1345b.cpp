/*
 * Leonardo Deliyannis Constantin
 * https://codeforces.com/contest/1345/problem/B
*/
 
#include<bits/stdc++.h>
using namespace std;
 
vector<int> p;
 
void gen(){
    int s = 0;
    p.push_back(0);
    while(p.back() < (int)(1e9)){
        p.push_back(p.back()+s+2 + (s>>1));
        s += 2;
    }
}
 
int main(){
    int t, n, ans;
    gen();
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        ans = 0;
        while(n >= 2){
            auto ptr = upper_bound(p.begin(), p.end(), n);
            ptr--;
            n -= *ptr;
            ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
