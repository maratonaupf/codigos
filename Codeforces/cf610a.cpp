/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/problemset/problem/610/A
*/

#include <stdio.h>

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        printf("%d\n", n&1 ? 0 : n%4 ? n/4 : n/4 - 1);
    }
    return 0;
}
