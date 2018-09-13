/*
 * Leonardo Deliyannis Constantin
 * URI 2116 - Diversão dos Alunos
*/

#include <stdio.h>

bool isPrime(int n){
    if(n < 2) return false;
    for(int i = 2; i*i <= n; i++)
        if(n%i == 0)
            return false;
    return true;
}

int main(){
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF){
        while(!isPrime(n)) n--;
        while(!isPrime(m)) m--;
        printf("%d\n", n*m);
    }
    return 0;
}
