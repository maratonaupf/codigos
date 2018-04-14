/*
 * Leonardo Deliyannis Constantin
 * URI 1554 - Bilhar N+1
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
    int T, N, id;
    int wx, wy, x, y;
    double dist, nudist;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        scanf("%d %d", &wx, &wy);
        dist = -1.0;
        for(int i = 1; i <= N; i++){
            scanf("%d %d", &x, &y);
            nudist = hypot(abs(x-wx), abs(y-wy));
            if(dist < 0.0 || nudist < dist){
                dist = nudist;
                id = i;
            }
        }
        printf("%d\n", id);
    }
    return 0;
}
