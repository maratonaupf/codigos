/*
 * Leonardo Deliyannis Constantin
 * URI 2847 - Papel, Tesoura, I Love You!
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 112345

int main(){
    char s[MAX];
    char t[] = "Ilveyu!";
    int i, cnt[256], ans;
    while(fgets(s, MAX, stdin) != NULL){
        memset(cnt, 0, sizeof(cnt));
        for(i = 0; s[i]; i++){
            cnt[(int)s[i]]++;
        }
        ans = cnt['o']/2;
        for(i = 0; t[i]; i++){
            ans = min(ans, cnt[(int)t[i]]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
