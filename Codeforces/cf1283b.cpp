/*
 * Leonardo Deliyannis Constantin
 * https://codeforces.com/contest/1283/problem/B
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n, k, x;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &k);
        x = (n/k) * k;
        printf("%d\n", min(n, x + k/2));
    }
    return 0;
}
