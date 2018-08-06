/*
 * Leonardo Deliyannis Constantin
 * URI 2418 - Carnaval
*/

#include <stdio.h>
#include <algorithm>

int main(){
    double v[5];
    while(scanf("%lf", v) != EOF){
        for(int i = 1; i < 5; i++){
            scanf("%lf", v+i);
        }
        std::sort(v, v+5);
        printf("%.1lf\n", v[1] + v[2] + v[3]);
    }
    return 0;
}
