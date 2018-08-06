/*
 * Leonardo Deliyannis Constantin
 * URI 2457 - Letras
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <set>
using namespace std;
#define MAX 1123

int main(){
    char c, s[MAX];
    int i, cnt, freq[26];
    while(scanf("%c ", &c) != EOF){
        fgets(s, MAX, stdin);
        memset(freq, 0, sizeof freq);
        cnt = 0;
        set<char> myset;
        for(i = 0; s[i]; i++){
            if(isalpha(s[i]))
                myset.insert(s[i]);
            else if(!myset.empty()){
                cnt++;
                for(char x : myset)
                    freq[x-'a']++;
                myset.clear();
            }
        }
        printf("%.1lf\n", (double)freq[c-'a']*100.0/(double)cnt);
    }
    return 0;
}
