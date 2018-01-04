/*
 * Leonardo Deliyannis Constantin
 * URI 2694 - Problema com a Calculadora
*/

#include <stdio.h>
#include <ctype.h>
#define MAX 22

typedef long long ll;

ll parseAndSum(const char *s){
    int i, tam = 0, in = 0;
    ll v[3];
    for(i = 0; i < 3; i++)
        v[i] = 0LL;
    for(i = 0; s[i]; i++){
        if(isdigit(s[i])){
        	in = 1;
        	v[tam] *= 10LL;
        	v[tam] += (ll) (s[i] - '0');
        }
        else if(in){
        	in = 0;
        	tam++;
        }
    }
    return v[0] + v[1] + v[2];
}

int main(){
    int N;
    char s[MAX];
    scanf("%d", &N);
    while(N--){
        scanf("%s", s);
        printf("%lld\n", parseAndSum(s));
    }
    return 0;
}
