/*
 * Leonardo Deliyannis Constantin
 * https://codeforces.com/contest/1337/problem/B
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, x, n, m;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &x, &n, &m);
        while(x > 20 && n > 0){
            x = (x/2) + 10;
            n--;
        }
        x -= m*10;
        printf("%s\n", (x <= 0) ? "YES" : "NO");
    }
    return 0;
}
