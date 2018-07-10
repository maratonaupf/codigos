/*
 * Leonardo Deliyannis Constantin
 * URI 2780 - Basquete de Robôs
*/ 

#include <stdio.h>

int main(){
    int d;
    while(scanf("%d", &d) != EOF){
        printf("%d\n", d <= 800 ? 1 : d <= 1400 ? 2 : 3);
    }
    return 0;
}
