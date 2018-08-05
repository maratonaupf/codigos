/*
 * Leonardo Deliyannis Constantin
 * URI 2579 - Nagol
*/

#include <stdio.h>

int main(){
    int l, c, x, y;
    while(scanf("%d %d %d %d", &l, &c, &x, &y) != EOF){
        if(c % 2 == 0)
            x = 0;
        printf("%s\n", ((x+y)&1) ? "Esquerda" : "Direita");
    }
    return 0;
}
