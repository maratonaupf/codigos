/*
 * Leonardo Deliyannis Constantin
 * https://codeforces.com/contest/1324/problem/A
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n, i, a;
    bool odd, even;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        odd = even = false;
        for(i = 0; i < n; i++){
            scanf("%d", &a);
            if(a&1)
                odd = true;
            else
                even = true;
        }
        printf("%s\n", (odd && even) ? "NO" : "YES");
    }
    return 0;
}
