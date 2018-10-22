/*
 * Leonardo Deliyannis Constantin
 * codeforces.com/problemset/problem/546/A
*/

#include <stdio.h>

int main(){
    int k, n, w, cost;
    while(scanf("%d %d %d", &k, &n, &w) != EOF){
        cost = k * (int)((double)(w+1) * (double)(w)/2.0);
        printf("%d\n", n >= cost ? 0 : cost - n);
    }
    return 0;
}
