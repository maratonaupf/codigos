/*
 * Leonardo Deliyannis Constantin
 * URI 2508 - Guru da Sorte
*/

#include <stdio.h>
#include <ctype.h>
#define MAX 112

int value(int c){
    return isalpha(c) ? ((toupper(c) - 'A') % 9) + 1: 0;
}

int main(){
    char s[MAX];
    int ans, i;
    while(fgets(s, MAX, stdin) != NULL){
        ans = 0;
        for(i = 0; s[i]; i++){
            ans += value(s[i]);
            if(ans > 9)
                ans = (ans/10) + (ans % 10);
        }
        printf("%d\n", ans);
    }
    return 0;
}
