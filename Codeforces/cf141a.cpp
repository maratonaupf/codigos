/*
 * Leonardo Deliyannis Constantin
 * https://codeforces.com/problemset/problem/141/A
*/

#include<bits/stdc++.h>
using namespace std;
#define MAX 112

int main(){
    string guest, host, pile;
    while(cin >> guest){
        cin >> host;
        cin >> pile;
        guest += host;
        if(guest.size() != pile.size()){
            cout << "NO\n";
            continue;
        }
        sort(guest.begin(), guest.end());
        sort(pile.begin(), pile.end());
        cout << (guest == pile ? "YES\n" : "NO\n");
    }
    return 0;
}
