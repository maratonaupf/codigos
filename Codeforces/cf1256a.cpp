/*
 * Leonardo Deliyannis Constantin
 * https://codeforces.com/contest/1256/problem/A
*/

#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
    int q, a, b, n, s, x;
    scanf("%d", &q);
    while(q--){
        scanf("%d %d %d %d", &a, &b, &n, &s);
        x = s/n;
        x = min(x, a);
        printf("%s\n", (x*n + b) >= s ? "YES" : "NO");
    }
    return 0;
}
