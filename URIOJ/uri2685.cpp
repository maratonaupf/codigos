/*
 * Leonardo Deliyannis Constantin
 * URI 2685 - A Mudança
*/

#include <stdio.h>

int main(){
    int M;
    char greet[4][20] = { 
        "Bom Dia!!", "Boa Tarde!!", "Boa Noite!!", "De Madrugada!!"
    };
    while(scanf("%d", &M) != EOF){
        if(M < 0 || M > 360)
            continue;
        M %= 360;
        printf("%s\n", greet[M/90]);
    }
    return 0;
}
