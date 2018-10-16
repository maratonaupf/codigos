/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/problemset/problem/58/A
*/

#include <stdio.h>
#include <string.h>

int main(){
    char s[112], t[6];
    int i, j;
    strcpy(t, "hello");
    while(scanf("%s ", s) != EOF){
        j = 0;
        for(i = 0; s[i]; i++){
            if(t[j] && s[i] == t[j])
                j++;
        }
        printf("%s\n", j == 5 ? "YES" : "NO");
    }
    return 0;
}
