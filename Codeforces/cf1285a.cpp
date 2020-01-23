/*
 * Leonardo Deliyannis Constantin
 * https://codeforces.com/contest/1285/problem/A
*/

#include<bits/stdc++.h>
using namespace std;
#define MAX 112345

int main(){
    int n, i, l, r;
    char s[MAX];
    while(scanf("%d", &n) != EOF){
        scanf(" %s", s);
        l = r = 0;
        for(i = 0; i < n; i++){
            if(s[i] == 'L')
                l++;
            if(s[i] == 'R')
                r++;
        }
        printf("%d\n", l + r + 1);
    }
    return 0;
}
