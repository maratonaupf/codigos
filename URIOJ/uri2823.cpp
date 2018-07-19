/*
 * Leonardo Deliyannis Constantin
 * URI 2823 - Earliest Deadline First
*/

#include <stdio.h>
#define EPS (1e-9)

int main(){
    int N, i, c, p;
    double sum;
    while(scanf("%d", &N) != EOF){
        sum = 0.0;
        for(i = 0; i < N; i++){
            scanf("%d %d", &c, &p);
            sum += (double)c / (double)p;
        }
        printf("%s\n", sum <= 1.0 + EPS ? "OK" : "FAIL");
    }
    return 0;
}
