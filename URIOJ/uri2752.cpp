/*
 * Leonardo Deliyannis Constantin
 * URI 2752 - Saída 6
*/

#include <stdio.h>

int main(){
    char s[] = "AMO FAZER EXERCICIO NO URI";
    printf("<%s>\n", s);
    printf("<%30s>\n", s);
    printf("<%.20s>\n", s);
    printf("<%-20s>\n", s);
    printf("<%-30s>\n", s);
    printf("<%.30s>\n", s);
    printf("<%30.20s>\n", s);
    printf("<%-30.20s>\n", s);
    return 0;
}
