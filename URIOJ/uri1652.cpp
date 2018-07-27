/*
 * Leonardo Deliyannis Constantin
 * URI 1652 - Deli Deli
*/

#include <stdio.h>
#include <ctype.h>
#include <string>
#include <map>
using namespace std;
#define LEN 21

inline int isVowel(int c){
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

string pluralize(string s){
    int l = (int)s.size()-1;
    if(s[l] == 'y' && !isVowel(s[l-1])){
        s[l] = 'i';
        return s + "es";
    }
    if(s[l] == 'o' || s[l] == 's' || s[l] == 'x' || 
      (s[l] == 'h' && (s[l-1] == 'c' || s[l-1] == 's')))
        return s + "es";
    return s + "s";
}

int main(){
    int L, N;
    char s[LEN], p[LEN];
    while(scanf("%d %d ", &L, &N) != EOF){
        map<string, string> pl;
        while(L--){
            scanf("%s %s ", s, p);
            pl[s] = p;
        }
        while(N--){
            scanf("%s ", s);
            printf("%s\n", pl.count(s) ? pl[s].c_str() : pluralize(s).c_str());
        }
    }
    return 0;
}
