/*
 * Leonardo Deliyannis Constantin
 * URI 2149 - Sequência do Tio Phill Bonati
*/

#include <stdio.h>
#define MAX 21

long long s[MAX];
void setup(){
    s[0] = 0;
    s[1] = 1;
    for(int i = 2; i < MAX; i++){
        s[i] = (i&1) ? (s[i-1] * s[i-2]) : (s[i-1] + s[i-2]);
    }
}

int main(){
    int N;
    setup();
    while(scanf("%d", &N) != EOF){
        printf("%lld\n", s[N-1]);
    }
    return 0;
}
