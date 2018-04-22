/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/problemset/problem/50/A
*/

#include <stdio.h>

int main(){
    int N, M;
    while(scanf("%d %d", &N, &M) != EOF){
        printf("%d\n", (N * M) / 2);
    }
    return 0;
}
