/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/contest/977/problem/A
*/

#include <stdio.h>

int subtract(int a, int b){
    while(b--){
        if(a%10 > 0){
            a--;
        }
        else{
            a /= 10;
        }
    }
    return a;
}

int main(){
    int a, b;
    while(scanf("%d %d", &a, &b) != EOF){
        printf("%d\n", subtract(a, b));
    }
    return 0;
}
