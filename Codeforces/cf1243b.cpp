#include<bits/stdc++.h>
using namespace std;
#define MAX 11234

int main(){
    int k, n, i, diffs;
    bool ans;
    scanf("%d", &k);
    char s[MAX], t[MAX];
    while(k--){
        scanf("%d ", &n);
        fgets(s, MAX, stdin);
        fgets(t, MAX, stdin);
        ans = true;
        diffs = 0;
        map<char, int> cs, ct;
        for(i = 0; i < n; i++){
            cs[s[i]]++;
            ct[t[i]]++;
            if(s[i] != t[i]){
                diffs++;
                if(diffs > 2){
                    ans = false;
                    break;
                }
            }
        }
        if(diffs != 2){
            ans = false;
        }
        diffs = 0;
        for(char c = 'a'; c <= 'z'; c++){
            if(cs[c] != ct[c]){
                diffs++;
                if(diffs > 2 || abs(cs[c]-ct[c]) != 2){
                    ans = false;
                }
            }
        }
        if(diffs != 2){
            ans = false;
        }
        printf("%s\n", ans ? "Yes" : "No");
    }
    return 0;
}
