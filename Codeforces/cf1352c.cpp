/*
 * Leonardo Deliyannis Constantin
 * https://codeforces.com/contest/1352/problem/C
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n, k;
    cin >> t;
    while(t--){
        cin >> n >> k;
        int ans = k+(k-1)/(n-1);
        cout << ans << '\n';
    }
    return 0;
}
