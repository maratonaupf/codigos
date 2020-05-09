/*
 * Leonardo Deliyannis Constantin
 * https://codeforces.com/problemset/problem/320/A
*/

#include<bits/stdc++.h>
using namespace std;

char erase = ' ';

void eliminate(const string p, string &s){
    int n = (int)s.size();
    int m = (int)p.size();
    for(int i = 0; i <= n-m; i++){
        bool found = true;
        for(int j = 0; j < m; j++){
            if(p[j] != s[i+j]){
                found = false;
                break;
            }
        }
        if(!found)
            continue;
        for(int j = 0; j < m; j++){
            s[i+j] = erase;
        }
        i += m-1;
    }
}

int main(){
    string n;
    while(cin >> n){
        eliminate("144", n);
        eliminate("14", n);
        eliminate("1", n);
        string aux;
        for(int i = 0; n[i]; i++){
            if(n[i] != erase)
                aux.push_back(n[i]);
        }
        n = aux;
        cout << (n.empty() ? "YES\n" : "NO\n");
    }
    return 0;
}
