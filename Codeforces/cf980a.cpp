/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/contest/980/problem/A
*/

#include <stdio.h>
#define MAX 112

int main(){
    char s[MAX];
    int i, l, p;
    while(scanf("%s", s) != EOF){
        for(i = l = p = 0; s[i]; i++){
            l += (s[i] == '-');
            p += (s[i] == 'o');
        }
        printf("%s\n", (p == 0 || l % p == 0) ? "YES" : "NO");
    }
    return 0;
}
