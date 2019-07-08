/*
 * Leonardo Deliyannis Constantin
 * Curso de Aperfeiçoamento em Programação Competitiva @ UPF 2019
 * Contest 1 - Problema D
 * URI 2880 - Enigma
*/

#include <stdio.h>
#include <string.h>
#define MAX 11234

int main(){
    int i, j, ans, lim;
    bool possible;
    char m[MAX], c[MAX];
    while(scanf("%s ", m) != EOF){
        scanf("%s ", c);
        ans = 0;
        lim = strlen(c)-1;
        for(i = 0; m[i+lim]; i++){
            possible = true;
            for(j = 0; c[j]; j++){
                if(c[j] == m[i+j]){
                    possible = false;
                    break;
                }
            }
            if(possible){
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
