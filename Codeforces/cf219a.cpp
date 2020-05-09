/*
 * Leonardo Deliyannis Constantin
 * https://codeforces.com/problemset/problem/219/A
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int k;
    string s;
    bool possible;
    while(cin >> k){
        cin >> s;
        map<char,int> cnt;
        for(char c : s){
            cnt[c]++;
        }
        possible = true;
        string ans;
        for(char c = 'a'; c <= 'z'; c++){
            if(cnt[c] % k == 0){
                for(int i = 0; i < cnt[c]/k; i++)
                    ans.push_back(c);
            }
            else{
                possible = false;
                break;
            }
        }
        if(possible){
            string aux = ans;
            for(k = k-1; k > 0; k--){
                ans += aux;
            }
            cout << ans << "\n";
        }
        else
            cout << "-1\n";
    }
    return 0;
}
