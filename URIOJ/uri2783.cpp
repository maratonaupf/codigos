/*
 * Leonardo Deliyannis Constantin
 * URI 2783 - Figurinhas da Copa
*/ 

#include <stdio.h>
#include <string.h>
#define MAX 112

int main(){
    int n, c, m, i, fig;
    int car[MAX];
    while(scanf("%d %d %d", &n, &c, &m) != EOF){
        memset(car, 0, sizeof(car));
        for(i = 0; i < c; i++){
            scanf("%d", &fig);
            car[fig] = 1;
        }
        while(m--){
            scanf("%d", &fig);
            if(car[fig]){
                c--;
                car[fig] = 0;
            }
        }
        printf("%d\n", c);
    }
    return 0;
}
