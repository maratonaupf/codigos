/*
 * Leonardo Deliyannis Constantin
 * URI 2551 - Novo Recorde
*/

#include <stdio.h>

int main(){
    int N, t, d;
    double record, currTime;
    while(scanf("%d\n", &N) != EOF){
        record = 0.0;
        for(int i = 1; i <= N; i++){
            scanf("%d %d", &t, &d);
            currTime = (double)d / double(t);
            if(currTime > record){
                record = currTime;
                printf("%d\n", i);
            }
        }
    }
    return 0;
}
