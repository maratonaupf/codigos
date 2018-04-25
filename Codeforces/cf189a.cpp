/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/problemset/problem/189/A
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 4123
#define INF ((int)1e9)

int memo[MAX];
int a, b, c;

int cut(int n){
    if(n == 0)
        return 0;
    if(n < 0)
        return -INF;
    if(memo[n] == -1)
        memo[n] = 1 + max(cut(n-a), max(cut(n-b), cut(n-c)));
    return memo[n];
}

int main(){
    int n;
    while(scanf("%d %d %d %d", &n, &a, &b, &c) != EOF){
        memset(memo, -1, sizeof(memo));
        printf("%d\n", cut(n));
    }
    return 0;
}
