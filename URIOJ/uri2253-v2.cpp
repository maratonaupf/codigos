/*
 * Leonardo Deliyannis Constantin
 * URI 2253 - Validador de Senhas
*/

#include <iostream>
#include <ctype.h>
using namespace std;

int main(){
    string s;
    bool hasUp, hasLow, hasNum, isValid;
    int i, len;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(getline(cin, s)){
        hasUp = hasLow = hasNum = false;
        isValid = true;
        len = (int)s.size();
        if(len < 6 || len > 32){
            isValid = false;
        }
        for(i = 0; isValid && s[i]; i++){
            hasUp   |= (bool) isupper(s[i]);
            hasLow  |= (bool) islower(s[i]);
            hasNum  |= (bool) isdigit(s[i]);
            if(!(isalnum(s[i]) && s[i] < 128)){
                isValid = false;
            }
        }
        if(!(hasUp && hasLow && hasNum))
            isValid = false;
        cout << "Senha " << (isValid ? "" : "in") << "valida.\n";
    }
    return 0;
}
