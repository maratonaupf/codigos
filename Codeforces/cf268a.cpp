/*
 * Leonardo Deliyannis Constantin
 * https://codeforces.com/problemset/problem/268/A
*/

#include<bits/stdc++.h>
using namespace std;
#define MAX 31

int main(){
    int n, i, j;
    // home kits, away kits
    int h[MAX], a[MAX];
    while(cin >> n){
        for(i = 0; i < n; i++){
            cin >> h[i] >> a[i];
        }
        int ans = 0;
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                if(i == j)
                    continue;
                if(h[i] == a[j])
                    ans += 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
