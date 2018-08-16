/*
 * Leonardo Deliyannis Constantin
 * URI 2376 - Copa do Mundo
*/

#include <stdio.h>

int main(){
    int M, N, i;
    char win[15];
    while(scanf("%d %d", &M, &N) != EOF){
        for(i = 0; i < 8; i++){
            if(i) scanf("%d %d", &M, &N);
            win[i] = 'A' + i*2 + (M < N);
        }
        for(i = 0; i < 4; i++){
            scanf("%d %d", &M, &N);
            win[8+i] = win[i*2 + (M < N)];
        }
        for(i = 0; i < 2; i++){
            scanf("%d %d", &M, &N);
            win[12+i] = win[8+i*2 + (M < N)];
        }
        scanf("%d %d", &M, &N);
        printf("%c\n", win[12 + (M < N)]);
    }
    return 0;
}
