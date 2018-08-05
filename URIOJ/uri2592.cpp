/*
 * Leonardo Deliyannis Constantin
 * URI 2592 - VaiNaSort
*/

#include <stdio.h>

int main(){
    int N, i, cur, ant;
    int cnt, sorted;
    while(scanf("%d", &N), N != 0){
        sorted = 0;
        cnt = 0;
        while(!sorted){
            cnt++;
            sorted = 1;
            for(i = 0; i < N; i++){
                scanf("%d", &cur);
                if(i > 0 && ant > cur)
                    sorted = 0;
                ant = cur;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
