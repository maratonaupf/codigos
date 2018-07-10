/*
 * Leonardo Deliyannis Constantin
 * URI 2815 - Digitador Gago
*/

#include <stdio.h>
#define MAX 16123

int main(){
    char s[MAX], t[MAX];
    int i, sz;
    while(fgets(s, MAX, stdin) != NULL){
        for(i = sz = 0; s[i] != '\n'; i++){
            if((i == 0 || s[i-1] == ' ')
            && (s[i] == s[i+2] && s[i+1] == s[i+3]))
                i += 2;
            t[sz++] = s[i];
        }
        t[sz] = 0;
        printf("%s\n", t);
    }
    return 0;
}
