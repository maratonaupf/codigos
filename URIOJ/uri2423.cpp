/*
 * Leonardo Deliyannis Constantin
 * URI 2423 - Receita de Bolo
*/

#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
    int a, b, c;
    while(scanf("%d %d %d", &a, &b, &c) != EOF){
        printf("%d\n", min(a/2, min(b/3, c/5)));
    }
    return 0;
}
