/*
 * Leonardo Deliyannis Constantin
 * Curso de Aperfeiçoamento em Programação Competitiva @ UPF 2019
 * Contest 1 - Problema A
 * URI 1129 - Leitura Ótica
*/

#include <stdio.h>
#include <string.h>

int main(){
    int N;
    int i, val;
    bool noans;
    char s[6], ans;
    strcpy(s, "ABCDE");
    while(scanf("%d", &N), N){
        while(N--){
            ans = '*';
            noans = true;
            for(i = 0; i < 5; i++){
                scanf("%d", &val);
                if(val <= 127){
                    if(noans){
                        ans = s[i];
                        noans = false;
                    }
                    else{
                        ans = '*';
                    }
                }
            }
            printf("%c\n", ans);
        }
    }
    return 0;
}
