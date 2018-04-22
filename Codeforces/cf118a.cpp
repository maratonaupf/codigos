/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/problemset/problem/118/A
*/

#include <stdio.h>
#include <ctype.h>
#define MAX 212

int isVowel(int c){
    c = toupper(c);
    return c == 'A' 
        || c == 'E' 
        || c == 'I' 
        || c == 'O' 
        || c == 'U' 
        || c == 'Y';
}

int main(){
    int sz, i;
    char s[MAX];
    char t[MAX];
    while(scanf("%s", s) != EOF){
        sz = 0;
        for(i = 0; s[i]; i++){
            if(!isVowel(s[i])){
                t[sz++] = '.';
                t[sz++] = tolower(s[i]);
            }
        }
        t[sz] = 0;
        printf("%s\n", t);
    }
    return 0;
}
