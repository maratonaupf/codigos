/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/contest/1095/problem/A
*/

#include <stdio.h>
#define MAX 112

int main(){
    int n, i, sz, inc;
    char s[MAX], t[MAX];
    while(scanf("%d %s", &n, s) != EOF){
        for(i = sz = inc = 0; i < n; i += ++inc){
            t[sz++] = s[i];
        }
        t[sz] = 0;
        printf("%s\n", t);
    }
    return 0;
}
