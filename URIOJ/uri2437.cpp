/*
 * Leonardo Deliyannis Constantin
 * URI 2437 - Distância de Manhattan
*/ 

#include <stdio.h>
#include <stdlib.h>

int main(){
    int x1, x2, y1, y2;
    while(scanf("%d %d %d %d", &x1, &y1, &x2, &y2) != EOF){
        printf("%d\n", abs(x1-x2) + abs(y1-y2));
    }
    return 0;
}
