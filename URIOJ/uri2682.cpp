/*
 * Leonardo Deliyannis Constantin
 * URI 2682 - Detector de Falhas
*/

#include <stdio.h>

int main(){
    bool ok = true;
    int curr, ant = -1, ans;
    while(scanf("%d", &curr) != EOF){
        if(ok && ant <= curr)
            ans = curr + 1;
        else
            ok = false;
        ant = curr;
    }
    printf("%d\n", ans);
    return 0;
}
