/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/problemset/problem/131/A
*/

#include <stdio.h>
#include <ctype.h>
#define MAX 112

int isCaps(const char *s){
    int i;
    for(i = 1; s[i]; i++)
        if(!isupper(s[i]))
            return 0;
    return 1;
}

void normalize(char *s){
    int i;
    s[0] = isupper(s[0]) ? tolower(s[0]) : toupper(s[0]);
    for(i = 1; s[i]; i++)
        s[i] = tolower(s[i]);
}

int main(){
    char s[MAX];
    while(scanf("%s", s) != EOF){
        if(isCaps(s))
            normalize(s);
        printf("%s\n", s);
    }
    return 0;
}
