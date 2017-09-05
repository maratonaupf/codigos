/*
 * Leonardo Deliyannis Constantin
 * URI 2651 - Link Bolado
 */

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 112345

char s[MAX];

int main(void){
    int i;
    while(fgets(s, MAX, stdin) != NULL){
        for(i = 0; s[i] != '\n'; i++){
            if(isupper(s[i])) s[i] = tolower(s[i]);
        }
        printf("Link %s\n", strstr(s, "zelda") != NULL ? 
            "Bolado" : "Tranquilo");
    }
    return 0;
}
