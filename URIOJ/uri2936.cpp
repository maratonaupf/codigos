/*
 * Leonardo Deliyannis Constantin
 * URI 2936 - Quanta Mandioca?
*/

#include <stdio.h>

int main(){
    int i, a[5], ans;
    const int w[5] = { 300, 1500, 600, 1000, 150 };
    while(scanf("%d", a) != EOF){
        ans = 225;
        for(i = 0; i < 5; i++){
            if(i > 0) 
                scanf("%d", a+i);
            ans += a[i] * w[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}
