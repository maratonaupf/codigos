/*
 * Leonardo Deliyannis Constantin
 * URI 2482 - Etiquetas de Noel
*/

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
    int N, M;
    string lang, msg, name;
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    while(cin >> N){
        cin.ignore();
        map<string, string> m;
        while(N--){
            getline(cin, lang);
            getline(cin, msg);
            m[lang] = msg;
        }
        cin >> M;
        cin.ignore();
        while(M--){
            getline(cin, name);
            getline(cin, lang);
            cout << name << endl << m[lang] << endl << endl;
        }
    }
    return 0;
}
