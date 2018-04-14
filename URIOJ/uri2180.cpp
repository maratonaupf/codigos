/*
 * Leonardo Deliyannis Constantin
 * URI 2180 - Viagem à Marte na Velocidade de Primo
*/

#include <stdio.h>
#define DIST 60000000

bool isPrime(int N){
    for(int i = 3; i*i <= N; i+=2)
        if(N%i == 0)
            return false;
    return true;
}

int main(){
    int N, i, cnt, sum;
    int hours, days;
    while(scanf("%d", &N) != EOF){
        cnt = sum = 0;
        for(i = N + (N%2 == 0); cnt < 10; i+=2){
            if(isPrime(i)){
                cnt++;
                sum += i;
            }
        }
        hours = DIST / sum;
        days = hours / 24;
        printf("%d km/h\n", sum);
        printf("%d h / %d d\n", hours, days);
    }
    return 0;
}
