/*
 * Leonardo Deliyannis Constantin
 * https://codeforces.com/problemset/problem/141/A
*/

#include<bits/stdc++.h>
using namespace std;
#define MAX 112

int main(){
    int i;
    bool ans;
    char guest[MAX], host[MAX], pile[MAX];
    while(scanf("%s", guest) != EOF){
        scanf(" %s", host);
        scanf(" %s", pile);
        map<char, int> c1, c2;
        for(i = 0; guest[i] != '\0'; i++){
            c1[guest[i]]++;
        }
        for(i = 0; host[i] != '\0'; i++){
            c1[host[i]]++;
        }
        for(i = 0; pile[i] != '\0'; i++){
            c2[pile[i]]++;
        }
        ans = true;
        for(char c = 'A'; c <= 'Z'; c++){
            if(c1[c] != c2[c]){
                ans = false;
                break;
            }
        }
        printf("%s\n", ans ? "YES" : "NO");
    }
    return 0;
}
