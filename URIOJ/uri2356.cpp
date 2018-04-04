/*
 * Leonardo Deliyannis Constantin
 * URI 2356 - Bactéria I 
*/

#include <stdio.h>
#include <string.h>
#define MAX 112

int main(){
    char d[MAX], s[MAX];
    while(scanf("%s", d) != EOF){
        scanf("%s", s);
        printf("%s\n", strstr(d, s) ? "Resistente" : "Nao resistente");
    }
    return 0;
}
