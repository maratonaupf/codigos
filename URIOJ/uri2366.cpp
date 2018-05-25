/*
 * Leonardo Deliyannis Constantin
 * URI 2366 - Maratona 
 * (Versão que passa em casos de teste MUITO malfeitos 
 *  que te dão um N e uma linha com MAIS de N valores)
*/

#include <stdio.h>

int main(){
    int M, prev, curr, ans;
    // Pra quê ler o N se a quantidade de valores pode ser diferente de N?
    scanf("%*d %d", &M);
    ans = 1;
    scanf("%d", &prev);
    while(scanf("%d", &curr) != EOF){
        ans &= curr - prev <= M;
        prev = curr;
    }
    curr = 42195;
    ans &= curr - prev <= M;
    printf("%c\n", ans ? 'S' : 'N');
    return 0;
}
