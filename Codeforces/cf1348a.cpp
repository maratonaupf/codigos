/*
 * Leonardo Deliyannis Constantin
 * https://codeforces.com/contest/1348/problem/A
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    ll n, i, p1, p2, ans;
    scanf("%d", &t);
    while(t--){
        scanf("%lld", &n);
        p1 = 0;
        p2 = 0;
        for(i = 1; i < n; i++){
            if(i < (ll) n/2){
                p1 += 1 << i;
            }
            else
                p2 += 1 << i;
        }
        p1 += 1 << n;
        ans = p1-p2;
        if(ans < 0ll)
            ans = -ans;
        printf("%lld\n", ans);
    }
    return 0;
}
