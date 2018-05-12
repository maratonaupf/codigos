/*
 * Leonardo Deliyannis Constantin
 * URI 2189 - Quermesse
*/

#include <stdio.h>

int main(){
    int N, i, x, tc = 0, win;
    while(scanf("%d", &N), N != 0){
        for(i = 1; i <= N; i++){
            scanf("%d", &x);
            if(x == i)
                win = x;
        }
        printf("Teste %d\n", ++tc);
        printf("%d\n\n", win);
    }
    return 0;
}
