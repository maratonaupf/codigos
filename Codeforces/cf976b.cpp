/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/contest/976/problem/B
*/

#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long ll;

int main(){
    ll n, m, k;
    ll i, j, c;
    while(scanf("%lld %lld %lld", &n, &m, &k) != EOF){
        if(k < n){
            i = k+1;
            j = 1;
        }
        else{
            i = n - ((k - n) / (m - 1));
            c = (k - n) % (m - 1);
            j = (i%2 == 0) ? (2 + c) : (m - c);
        }
        printf("%d %d\n", (int)i, (int)j);
    }
    return 0;
}
