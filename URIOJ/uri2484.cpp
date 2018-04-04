/*
 * Leonardo Deliyannis Constantin
 * URI 2484 - Abracadabra
*/

#include <stdio.h>
#include <string.h>
#define MAX 1123

int main(){
    char s[MAX];
    int sz, i, j;
    while(scanf("%s", s) != EOF){
        sz = strlen(s);
        for(j = 0; s[j]; j++){
            printf("%*s", j, "");
            for(i = 0; i < sz - j; i++){
                printf("%c%c", s[i], i < sz-j-1 ? ' ' : '\n');
            }
        }
        printf("\n");
    }
    return 0;
}
