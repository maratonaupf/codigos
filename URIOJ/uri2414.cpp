/*
 * Leonardo Deliyannis Constantin
 * URI 2414 - Desafio do Maior Número
*/ 

#include <stdio.h>

int main(){
    int n, maior = 0;
    while(scanf("%d", &n), n != 0){
        if(n > maior)
            maior = n;
    }
    printf("%d\n", maior);
    return 0;
}
