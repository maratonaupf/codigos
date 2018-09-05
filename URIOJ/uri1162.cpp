/*
 * Leonardo Deliyannis Constantin
 * URI 1162 - Organizador de Vagões
*/

#include <stdio.h>
#include <algorithm>
#define MAX 52

int main(){
    int T, N, i, j, cnt, v[MAX];
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        for(i = 0; i < N; i++){
            scanf("%d", &v[i]);
        }
        cnt = 0;
        for(i = 0; i < N; i++){
            for(j = 1; j < N-i; j++){
                if(v[j-1] > v[j]){
                    std::swap(v[j-1], v[j]);
                    cnt++;
                }
            }
        }
        printf("Optimal train swapping takes %d swaps.\n", cnt);
    }
    return 0;
}
