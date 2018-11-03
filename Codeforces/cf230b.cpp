/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/problemset/problem/230/B
*/

#include <iostream>
#include <bitset>
#include <set>
using namespace std;
#define MAX 1123456LL

typedef long long ll;

set<ll> tprimes;

void sieve(){
    bitset<MAX> bs;
    bs.set();
    bs[0] = bs[1] = false;
    for(ll i = 2; i < MAX; i++) if(bs[i]) {
        tprimes.insert(i*i);
        for(ll j = i*i; j < MAX; j += i)
            bs[j] = false;
    }
}

int main(){
    ll n, x;
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    sieve();
    while(cin >> n){
        while(n--){
            cin >> x;
            cout << (tprimes.count(x) ? "YES" : "NO") << "\n";
        }
    }
    return 0;
}
