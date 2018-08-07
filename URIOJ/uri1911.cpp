/*
 * Leonardo Deliyannis Constantin
 * URI 1911 - Ajude Girafales
*/

#include <stdio.h>
#include <unordered_map>
#include <string>
using namespace std;
#define LEN 22

int main(){
    int N, M, ans, dif;
    char s[LEN], t[LEN];
    while(scanf("%d ", &N), N){
        unordered_map<string, string> sig;
        while(N--){
            scanf("%s %s ", s, t);
            sig[s] = t;
        }
        ans = 0;
        scanf("%d", &M);
        while(M--){
            dif = 0;
            scanf("%s %s ", s, t);
            for(int i = 0; t[i] && dif <= 1; i++){
                if(sig[s][i] != t[i])
                    dif++;
            }
            if(dif > 1)
                ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
