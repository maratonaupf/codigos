/*
 * Leonardo Deliyannis Constantin
 * URI 2938 - Jaçanã
*/

#include <stdio.h>

int main(){
    int p, c, n, i, v, cap, load, cnt;
    bool drown;
    while(scanf("%d %d %d", &p, &c, &n) != EOF){
        cnt = 0;
        load = c;
        drown = false;
        for(i = 0; i < n; i++){
            scanf("%d", &v);
            cap = v - p;
            if(cap < 0){
                drown = true;
            }
            if(cap < load){
                load = cap;
                if(!drown && i > 0){
                    cnt++;
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
