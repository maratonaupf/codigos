/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/problemset/problem/469/A
*/

#include <stdio.h>
#include <string.h>
#define MAX 112

int main(){
    int n, p, a, pass[MAX];
    while(scanf("%d", &n) != EOF){
        memset(pass, 0, sizeof(pass));
        scanf("%d", &p);
        while(p--){
            scanf("%d", &a);
            if(!pass[a]){
                pass[a] = 1;
                n--;
            }
        }
        scanf("%d", &p);
        while(p--){
            scanf("%d", &a);
            if(!pass[a]){
                pass[a] = 1;
                n--;
            }
        }
        printf("%s\n", n == 0 ? "I become the guy." : "Oh, my keyboard!");
    }
    return 0;
}
