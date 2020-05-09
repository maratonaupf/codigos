/*
 * Leonardo Deliyannis Constantin
 * https://codeforces.com/contest/1316/problem/A
*/

#include<bits/stdc++.h>
using namespace std;
#define MAX 1123

int main(){
    int t, n, m;
    int i, a[MAX], tot;
    // double avg;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        tot = 0;
        for(i = 0; i < n; i++){
            scanf("%d", a+i);
            tot += a[i];
        }
        // avg = (double) tot / (double) n;
        printf("%d\n", min(m, tot));
    }
    return 0;
}
