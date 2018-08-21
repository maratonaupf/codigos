/*
 * Leonardo Deliyannis Constantin
 * URI 2850 - Papagaio Poliglota
*/

#include <stdio.h>
#define MAX 21

int main(){
    char s[MAX];
    while(fgets(s, MAX, stdin)){
        printf("%s\n", s[0] == 'e' ? "ingles" : s[0] == 'd' ? "frances" :
            s[0] == 'n' ? "portugues" : "caiu");
    }
    return 0;
}
