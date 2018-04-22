/*
 * Leonardo Deliyannis Constantin
 * CF 71A - Way Too Long Words
*/

#include <stdio.h>
#include <string.h>
#define MAX 112

int main(){
    int N, tam;
    char s[MAX];
    scanf("%d", &N);
    while(N--){
        scanf("%s", s);
        tam = int(strlen(s));
        if(tam > 10)
            printf("%c%d%c\n", s[0], tam-2, s[tam-1]);
        else
            printf("%s\n", s);
    }
    return 0;
}
