/*
 * Leonardo Deliyannis Constantin
 * URI 2150 - Vogais Alienígenas
*/

#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(){
    string v, s;
    ios::sync_with_stdio(false);
    while(cin >> v){
        set<char> vow;
        for(int i = 0; v[i]; i++){
            vow.insert(v[i]);
        }
        cin.ignore();
        getline(cin, s);
        int cnt = 0;
        for(int i = 0; s[i]; i++){
            if(vow.count(s[i])){
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
