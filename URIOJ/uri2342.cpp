/*
 * Leonardo Deliyannis Constantin
 * URI 2342 - Overflow
*/

#include <stdio.h>

int main(){
    int n, a, b;
    char o;
    while(scanf("%d", &n) != EOF){
        scanf("%d %c %d", &a, &o, &b);
        printf("%s\n", n >= (o == '+' ? (a+b) : (a*b)) ? "OK" : "OVERFLOW");
    }
    return 0;
}
