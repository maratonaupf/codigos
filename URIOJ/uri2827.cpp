/*
 * Leonardo Deliyannis Constantin
 * URI 2827 - Contador de Tokens
*/

#include <iostream>
#include <ctype.h>
#include <string>
#include <map>
using namespace std;
#define MAX 112345

int main(){
    string s;
    string tok, most;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while(getline(cin, s)){
        tok = "__";
        map<string, int> freq;
        for(int i = 0; s[i+1] != '\0'; i++){
            tok[0] = tolower(s[i]);
            tok[1] = tolower(s[i+1]);
            freq[tok]++;
        }
        most = "";
        for(auto f : freq){
            if(most == "" || f.second > freq[most] ||
            (f.second == freq[most] && f.first < most))
                most = f.first;
        }
        cout << most << ":" << freq[most] << endl;
    }
    return 0;
}
