/*
 * Leonardo Deliyannis Constantin
 * https://codeforces.com/contest/1335/problem/B
*/

#include<bits/stdc++.h>
using namespace std;
#define MAX 2123

int main(){
    int t, n, a, b;
    int i, j;
    scanf("%d", &t);
    char s[MAX];
    while(t--){
        scanf("%d %d %d", &n, &a, &b);
        for(i = 0; i < n; i++){
            int dif = 0;
            int must = min(i+1, b);
            map<char, int> cnt;
            for(j = max(i-(a-1), 0); j < i; j++){
                if(cnt[s[j]] == 0){
                    dif++;
                }
                cnt[s[j]]++;
            }
            for(char c = 'a'; c <= 'z'; c++){
                if((dif < must && cnt[c] == 0)
                || (dif >= must && cnt[c] > 0)){
                    s[i] = c;
                    break;
                }
            }
        }
        s[n] = '\0';
        printf("%s\n", s);
    }
    return 0;
}
