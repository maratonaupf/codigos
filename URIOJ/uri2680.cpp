/*
 * Leonardo Deliyannis Constantin
 * URI 2680 - Folha de Pagamentos
*/

#include <stdio.h>

typedef long long ll;

ll sumDiv(int M){
    ll ret = 0;
    for(int i = 1; i*i <= M; i++){
        if(M % i == 0){
            ret += (ll)i;
            if(i != M/i){
                ret += (ll)(M/i);
            }
        }
    }
    return ret;
}

int main(){
    int N, M;
    scanf("%d", &N);
    while(N--){
        scanf("%d", &M);
        printf("%lld\n", sumDiv(M));
    }
    return 0;
}
