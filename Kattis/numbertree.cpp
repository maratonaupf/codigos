/*
 * Leonardo Deliyannis Constantin
 * https://open.kattis.com/problems/numbertree
*/

#include <stdio.h>
#define MAX 32

int main(){
    int H, ans;
    char s[MAX];
    while(scanf("%d ", &H) != EOF){
        ans = 1;
        if(fgets(s, MAX, stdin) != NULL){
            for(int i = 0; s[i] != '\n'; i++){
                ans *= 2;
                if(s[i] == 'R') 
                    ans++;
            }
        }
        printf("%d\n", (2 << H) - ans);
    }
    return 0;
}
