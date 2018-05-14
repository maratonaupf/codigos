/*
 * Leonardo Deliyannis Constantin
 * http://br.spoj.com/problems/COMETA2/
*/

#include <stdio.h>

int main(){
    int Y;
    while(scanf("%d", &Y) != EOF){
        printf("%d\n", ((Y-1986) / 76 + 1) *76 + 1986);
    }
    return 0;
}
