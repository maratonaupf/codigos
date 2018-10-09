/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/problemset/problem/266/A
*/

#include <stdio.h>
#define MAX 52

int main(){
    char s[MAX];
    int n, i, cnt;
    while(scanf("%d %s", &n, s) != EOF){
        cnt = 0;
        for(i = 1; s[i]; i++){
            if(s[i-1] == s[i])
                cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
