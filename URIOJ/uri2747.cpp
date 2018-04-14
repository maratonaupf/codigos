/*
 * Leonardo Deliyannis Constantin
 * URI 2747 - Saída 1
*/

#include <stdio.h>

int main(){
    int i;
    char   line[40] = "---------------------------------------";
    char middle[40] = "|                                     |";
    printf("%s\n", line);
    for(i = 0; i < 5; i++){
        printf("%s\n", middle);
    }
    printf("%s\n", line);
    return 0;
}
