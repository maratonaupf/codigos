/*
 * Leonardo Deliyannis Constantin
 * URI 2508 - Guru da Sorte
*/

#include <stdio.h>
#include <ctype.h>
#define MAX 1123

int value(int c){
    return ((toupper(c) - 'A') % 9) + 1;
}

int singleDigit(int c){
    int ans = 0;
    while(c > 0){
        ans += c % 10;
        c /= 10;
    }
    return ans;
}

int main(){
    char s[MAX];
    int ans, i;
    while(fgets(s, MAX, stdin) != NULL){
        ans = 0;
        for(i = 0; s[i]; i++){
            if(isalpha(s[i]))
                ans += value(s[i]);
        }
        while(ans > 9)
            ans = singleDigit(ans);
        printf("%d\n", ans);
    }
    return 0;
}
