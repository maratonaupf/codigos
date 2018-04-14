/*
 * Leonardo Deliyannis Constantin
 * URI 2455 - Gangorra
*/

#include <stdio.h>

int main(){
    int p1, c1, p2, c2, ans;
    while(scanf("%d %d %d %d", &p1, &c1, &p2, &c2) != EOF){
        ans = p2*c2 - p1*c1;
        printf("%d\n", ans == 0 ? 0 : ans < 0 ? -1 : 1);
    }
    return 0;
}
