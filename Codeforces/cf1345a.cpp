/*
 * Leonardo Deliyannis Constantin
 * https://codeforces.com/contest/1345/problem/A
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n, m;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        if((n <= 2 && m <= 2) || n == 1 || m == 1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
