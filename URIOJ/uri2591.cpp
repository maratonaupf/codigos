/*
 * Leonardo Deliyannis Constantin
 * URI 2591 - HameKameKa
*/

#include <stdio.h>
#define MAX 212

int main(){
    int N, i, c1, c2;
    char s[MAX];
    scanf("%d", &N);
    while(N--){
        scanf("%s", s);
        c1 = c2 = 0;
        for(i = 0; s[i] != 'a'; i++);
        for(; s[i] == 'a'; i++)
            c1++;
        for(; s[i] != 'a'; i++);
        for(; s[i] == 'a'; i++)
            c2++;
        putchar('k');
        for(i = 0; i < c1*c2; i++)
            putchar('a');
        putchar('\n');
    }
    return 0;
}
