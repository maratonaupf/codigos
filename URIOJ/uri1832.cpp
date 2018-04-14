/*
 * Leonardo Deliyannis Constantin
 * URI 1832 - EBCDIC
*/

#include <iostream>
#include <string>
using namespace std;
#define MAX 256

char cod[MAX];

void subsetup(int begin, const char *s){
    for(int i = 0; s[i]; i++){
        cod[begin+i] = s[i];
    }
}

void setup(){
    cod[64] = ' ';
    subsetup(129, "abcdefghi");
    subsetup(145, "jklmnopqr");
    subsetup(162, "stuvwxyz");
    subsetup(193, "ABCDEFGHI");
    subsetup(209, "JKLMNOPQR");
    subsetup(226, "STUVWXYZ");
    subsetup(240, "0123456789");
}

int main(){
    string s;
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    setup();
    while(getline(cin, s)){
        int num = 0;
        string text = "";
        for(int i = 0; s[i]; i++){
            if(i%4 == 0)
                num += (s[i] - '0') * 64; 
            if(i%4 == 1)
                num += (s[i] - '0') * 8;
            if(i%4 == 2)
                num += (s[i] - '0');
            if(i%4 == 3 || s[i+1] == '\0'){
                text.push_back(cod[num]);
                num = 0;
            } 
        }
        cout << text << endl;
    }
    return 0;
}
