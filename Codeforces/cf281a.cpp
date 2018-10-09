/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/problemset/problem/281/A
*/

#include <stdio.h>
#include <ctype.h>
#define MAX 1123

int main(){
    char s[MAX];
    while(scanf("%s ", s) != EOF){
        s[0] = toupper(s[0]);
        printf("%s\n", s);
    }
    return 0;
}
