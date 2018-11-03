/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/problemset/problem/550/A
*/

#include <stdio.h>
#include <string.h>
#define MAX 112345

int main(){
    char s[MAX];
    int i, j, k;
    bool ans;
    while(scanf("%s", s) != EOF){
        ans = false;
        j = MAX;
        k = MAX;
        for(i = 0; s[i+1]; i++){
            if(s[i] == 'A' && s[i+1] == 'B'){
                if(j > i)
                    j = i;
                if(i - k > 1)
                    ans = true;
            }
            if(s[i] == 'B' && s[i+1] == 'A'){
                if(k > i)
                    k = i;
                if(i - j > 1)
                    ans = true;
            }
        }
        printf("%s\n", ans ? "YES" : "NO");
    }
    return 0;
}
