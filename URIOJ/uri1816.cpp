/*
 * Leonardo Deliyannis Constantin
 * URI 1816 - Vikings em Praga?
*/

#include <stdio.h>
#include <string.h>
#define LEN 11234

char code[27];

void moveToTop(int i){
    char top = code[i];
    memmove(code+1, code, i);
    code[0] = top;
}

int main(){
    char s[LEN];
    int N, sz, val, test = 0;
    while(scanf("%d", &N), N != 0){
        strcpy(code, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
        for(sz = 0; sz < N; sz++){
            scanf("%d", &val);
            moveToTop(val-1);
            s[sz] = code[0];
        }
        s[sz] = '\0';
        printf("Instancia %d\n", ++test);
        printf("%s\n\n", s);
    }
    return 0;
}
