/*
 * Leonardo Deliyannis Constantin
 * URI 2915 - Mount Marathon
*/

#include <stdio.h>

int main(){
    int N, i, curr, prev, cnt;
    while(scanf("%d", &N) != EOF){
        scanf("%d", &prev);
        cnt = 1;
        for(i = 1; i < N; i++){
            scanf("%d", &curr);
            if(prev < curr)
                cnt++;
            prev = curr;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
