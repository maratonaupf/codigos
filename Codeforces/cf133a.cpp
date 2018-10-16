/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/problemset/problem/133/A
*/

#include <stdio.h>
#define MAX 112

int main(){
    int i, ans;
    char s[MAX];
    while(fgets(s, MAX, stdin)){
        ans = 0;
        for(i = 0; s[i]; i++){
            ans |= (s[i] == 'H' || s[i] == 'Q' || s[i] == '9');
        }
        printf("%s\n", ans ? "YES" : "NO");
    }
    return 0;
}
