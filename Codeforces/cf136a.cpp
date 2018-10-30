/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/problemset/problem/136/A
*/

#include <stdio.h>
#define MAX 112

int main(){
    int n, i, f, p[MAX];
    while(scanf("%d", &n) != EOF){
        for(i = 1; i <= n; i++){
            scanf("%d", &f);
            p[f] = i;
        }
        for(i = 1; i <= n; i++)
            printf("%d%c", p[i], i < n ? ' ' : '\n');
    }
    return 0;
}
