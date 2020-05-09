/*
 * Leonardo Deliyannis Constantin
 * https://codeforces.com/contest/1352/problem/A
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> solve(int n){
    vector<int> ans;
    int pot = 1;
    while(n > 0){
        if(n % 10 != 0){
            ans.push_back(n % 10 * pot);
        }
        pot *= 10;
        n /= 10;
    }
    return ans;
}

int main(){
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        vector<int> ans = solve(n);
        printf("%d\n", (int)ans.size());
        for(int i = (int)ans.size()-1; i >= 0; i--){
            printf("%d ", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
