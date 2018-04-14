/*
 * Leonardo Deliyannis Constantin
 * URI 2766 - Entrada e Saída Lendo e Pulando Nomes
*/

#include <stdio.h>
#define MAX 32

int main(){
    int i;
    char s[32];
    for(i = 1; i <= 10; i++){
        scanf("%s", s);
        if(i == 3 || i == 7 || i == 9)
            printf("%s\n", s);
    }
    return 0;
}
