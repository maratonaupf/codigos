/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/contest/976/problem/A
*/

#include <stdio.h>
#define MAX 112

int main(){
    int n, i, cnt;
    char s[MAX];
    while(scanf("%d", &n) != EOF){
        scanf("%s", s);
        if(n != 1){
            cnt = 0;
            for(i = 0; s[i] != '\0'; i++)
                if(s[i] == '0')
                    cnt++;
            s[0] = '1';
            for(i = 1; i <= cnt; i++)
                s[i] = '0';
            s[i] = '\0';
        }
        printf("%s\n", s);
    }
    return 0;
}
