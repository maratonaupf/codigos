/*
 * Leonardo Deliyannis Constantin
 * URI 2424 - Tira-teima
*/

#include <stdio.h>

int main(){
    int x, y;
    while(scanf("%d %d", &x, &y) != EOF){
        printf("%s\n", 0 <= x && x <= 432 && 0 <= y && y <= 468 ? 
            "dentro" : "fora");
    }
    return 0;
}
