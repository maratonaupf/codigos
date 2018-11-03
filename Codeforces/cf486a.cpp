/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/problemset/problem/486/A
*/

#include <iostream>
using namespace std;

typedef long long ll;

int main(){
    ll n;
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    while(cin >> n){
        ll ans = (n+1)/2 * (n&1LL ? -1LL : 1LL);
        cout << ans << "\n";
    }
    return 0;
}
