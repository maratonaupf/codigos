/*
 * Leonardo Deliyannis Constantin
 * URI 2787 - Xadrez
*/ 

#include <stdio.h>

int main(){
    int l, c;
    while(scanf("%d %d", &l, &c) != EOF){
        printf("%d\n", ~(l+c)&1);
    }
    return 0;
}
