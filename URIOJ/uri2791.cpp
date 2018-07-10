/*
 * Leonardo Deliyannis Constantin
 * URI 2791 - Feijão
*/ 

#include <stdio.h>

int main(){
    int c, ans, i;
    while(scanf("%d", &c) != EOF){
        for(i = 1; i <= 4; i++){
            if(i > 1) scanf("%d", &c);
            if(c) ans = i;
        }
        printf("%d\n", ans);
    }
    return 0;
}
