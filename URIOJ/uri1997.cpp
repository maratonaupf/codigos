/*
 * Leonardo Deliyannis Constantin
 * URI 1997 - Branco e Preto
*/

#include <stdio.h>
#define MAX 512

int main(){
    char s[MAX], t[MAX];
    int i, cnt, ans;
    while(scanf("%s %s", s, t), s[0] != '*'){
        cnt = ans = 0;
        for(i = 0; s[i]; i++){
            if(s[i] != t[i]){
                cnt++;
            }
            if((s[i] == t[i] || s[i+1] == '\0') && (cnt > 0)){
                cnt = 0;
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
