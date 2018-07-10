/*
 * Leonardo Deliyannis Constantin
 * URI 2782 - Escadinha
*/ 

#include <stdio.h>
#include <stdlib.h>
#define MAX 1123
#define INF 0x3f3f3f3f

int main(){
    int N, i, v[MAX], cnt, dif;
    while(scanf("%d", &N) != EOF){
        cnt = 1;
        dif = INF;
        for(i = 0; i < N; i++){
            scanf("%d\n", &v[i]);
            if(i == 1)
                dif = abs(v[i-1]-v[i]);
            if(i <= 1) 
                continue;
            if(abs(v[i-1]-v[i]) != dif){
                dif = abs(v[i-1]-v[i]);
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
