/*
 * Leonardo Deliyannis Constantin
 * URI 2587 - Jetiqui
*/

#include <stdio.h>
#include <string.h>
#define MAX 17

int main(){
    int C, i, p1, p2;
    char s[MAX], t[MAX], u[MAX];
    scanf("%d ", &C);
    while(C--){
        fgets(s, MAX, stdin);
        fgets(t, MAX, stdin);
        fgets(u, MAX, stdin);
        p1 = p2 = -1;
        for(i = 0; s[i+1]; i++)
            if(u[i] == '_'){
                if(p1 == -1) p1 = i;
                else p2 = i;
            }
        printf("%c\n", s[p1] == t[p2] || s[p2] == t[p1] ? 'Y' : 'N');
    }
    return 0;
}
