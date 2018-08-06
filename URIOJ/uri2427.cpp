/*
 * Leonardo Deliyannis Constantin
 * URI 2427 - Chocolate
*/

#include <cstdio>
#include <cmath>
using namespace std;

int exp(int a, int b){
    if(b == 0) return 1;
    if(b &  1) return a * exp(a * a, b >> 1);
    return exp(a * a, b >> 1);
}

int main(){
    int N;
    while(scanf("%d", &N) != EOF){
        printf("%d\n", exp(4, (int)log2(N)));
    }
    return 0;
}
