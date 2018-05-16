/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/contest/978/problem/B
*/

#include <stdio.h>
#define MAX 112

int main(){
    int n, i, cnt, ans;
    char s[MAX];
    while(scanf("%d", &n) != EOF){
        scanf("%s", s);
        for(i = cnt = ans = 0; s[i]; i++){
            if(s[i] != 'x')
                cnt = 0;
            else
                (cnt < 2) ? cnt++ : ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
