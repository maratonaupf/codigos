/*
 * Leonardo Deliyannis Constantin
 * URI 2835 - Elevador
*/

#include <stdio.h>
#include <algorithm>
#define MAX 11234

int main(){
    int N, i, v[MAX];
    while(scanf("%d", &N) != EOF){
        v[0] = 0;
        for(i = 1; i <= N; i++){
            scanf("%d", v+i);
        }
        std::sort(v+1, v+1+N);
        bool ans = true;
        for(i = 1; i <= N; i++){
            if(v[i] - v[i-1] > 8)
                ans = false;
        }
        printf("%c\n", ans ? 'S' : 'N');
    }
    return 0;
}
