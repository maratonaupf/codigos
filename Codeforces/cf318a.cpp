/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/problemset/problem/318/A
*/

#include <iostream>
using namespace std;

typedef long long ll;

inline ll solve(ll n, ll k){
    if(k-(n&1LL) <= n/2LL)
        return (k-1LL)*2LL+1LL;
    return (k-(n&1LL)-n/2LL)*2LL;
}

int main(){
    ll n, k;
    while(cin >> n >> k){
        cout << solve(n, k) << endl;
    }
    return 0;
}
