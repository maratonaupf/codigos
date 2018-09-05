/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/contest/1015/problem/B
*/

#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
#define LEN 52

int main(){
    int n, i, j, pos;
    char s[LEN], t[LEN];
    while(scanf("%d", &n) != EOF){
        scanf(" %s %s", s, t);
        vector<int> ans;
        for(i = 0; i < n; i++){
            if(s[i] == t[i]) continue;
            pos = -1;
            for(j = i+1; j < n; j++){
                if(s[j] == t[i]){
                    pos = j;
                    break;
                }
            }
            if(pos == -1){
                ans.clear();
                break;
            }
            for(j = pos - 1; j >= i; j--){
                swap(s[j], s[j+1]);
                ans.push_back(j+1);
            }
        }
        printf("%d\n", strcmp(s, t) ? -1 : (int)ans.size());
        for(int i : ans)
            printf("%d ", i);
        if(!ans.empty())
            printf("\n");
    }
    return 0;
}
