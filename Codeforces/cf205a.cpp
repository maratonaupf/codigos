/*
 * Leonardo Deliyannis Constantin
 * https://codeforces.com/problemset/problem/205/A
*/

#include<bits/stdc++.h>
using namespace std;
#define MAX 112345

int main(){
    int n;
    int c[MAX];
    while(cin >> n){
        int ans = 1;
        bool repeated = false;
        for(int i = 1; i <= n; i++){
            cin >> c[i];
            if(i == 1)
                continue;
            if(c[i] == c[ans]){
                repeated = true;
            }
            if(c[i] < c[ans]){
                ans = i;
                repeated = false; 
            }
        }
        if(repeated)
            cout << "Still Rozdil\n";
        else
            cout << ans << "\n";
    }
    return 0;
}
