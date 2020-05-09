/*
 * Leonardo Deliyannis Constantin
 * https://codeforces.com/contest/1335/problem/D
*/

#include<bits/stdc++.h>
using namespace std;
#define MAX 11

int main(){
    int t, i, j;
    const int n = 9;
    char s[MAX];
    scanf("%d", &t);
    while(t--){
        for(i = 0; i < n; i++){
            scanf(" %s", s);
            for(j = 0; j < n; j++){
                if(s[j] == '2')
                    s[j] = '1';
            }
            printf("%s\n", s);
        }
    }    
    return 0;
}
