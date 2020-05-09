/*
 * Leonardo Deliyannis Constantin
 * https://codeforces.com/contest/1341/problem/A
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, i, s1, s2;
    int n, a, b, c, d;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d %d %d", &n, &a, &b, &c, &d);
        s1 = (a-b) * n;
        s2 = (a+b) * n;
        if(s2 < (c-d) || (c+d) < s1)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}

