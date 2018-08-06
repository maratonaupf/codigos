/*
 * Leonardo Deliyannis Constantin
 * URI 2175 - Qual o Mais Rápido?
*/

#include <stdio.h>

int main(){
    double o, b, i;
    while(scanf("%lf %lf %lf", &o, &b, &i) != EOF){
        printf("%s\n", (o < b && o < i) ? "Otavio" : (o > b && b < i) ? 
            "Bruno" : (o > i && b > i) ? "Ian": "Empate");
    }
    return 0;
}
