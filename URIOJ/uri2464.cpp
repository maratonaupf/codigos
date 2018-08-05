/*
 * Leonardo Deliyannis Constantin
 * URI 2464 - Decifra
*/

#include <stdio.h>
#define MAX 11234

int main(){
    int i;
    char cod[32], s[MAX];
    while(scanf("%s %s", cod, s) != EOF){
        for(i = 0; s[i]; i++){
            s[i] = cod[s[i] - 'a'];
        }
        printf("%s\n", s);
    }
    return 0;
}
