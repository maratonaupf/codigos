/*
 * Leonardo Deliyannis Constantin
 * URI 1068 - Balanço de Parênteses
*/ 

#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> s){
        int cont = 0;
        bool correct = true;
        for(int i = 0; i < (int)s.size(); i++){
            if(s[i] == '('){
                cont++;
            }
            if(s[i] == ')'){
                cont--;
                if(cont < 0)
                    correct = false;
            }
        }
        if(cont != 0)
            correct = false;
        if(correct)
            cout << "correct\n";
        else
            cout << "incorrect\n";
    }
    return 0;
}
