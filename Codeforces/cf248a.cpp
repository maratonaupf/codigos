/*
 * Leonardo Deliyannis Constantin
 * https://codeforces.com/problemset/problem/248/A
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, i, l, r;
    int ans;
    while(cin >> n){
        int leftZeroes = 0, rightZeroes = 0;
        int leftOnes = 0, rightOnes = 0;
        for(i = 0; i < n; i++){
            cin >> l >> r;
            if(l == 0)
                leftZeroes++;
            else
                leftOnes++;
            if(r == 0)
                rightZeroes++;
            else
                rightOnes++;
        }
        ans = min(leftOnes, leftZeroes) + min(rightZeroes, rightOnes);
        cout << ans << "\n";
    }
    return 0;
}
