/*
 * Leonardo Deliyannis Constantin
 * URI 2852 - Troca de Mensagens
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 112345

bool isVowel(int c){
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool consonant(int c){
    return isalpha(c) && !isVowel(c);
}

int main(){
    int N, sz;
    char k[52], s[MAX];
    while(scanf(" %s", k) != EOF){
        sz = strlen(k);
        scanf("%d ", &N);
        while(N--){
            fgets(s, MAX, stdin);
            bool cipher = false;
            for(int i = 0, j = 0; s[i]; i++){
                if(consonant(s[i]) && (i == 0 || !isalpha(s[i-1])) && !cipher)
                    cipher = true;
                if(!isalpha(s[i]))
                    cipher = false;
                if(cipher){
                    s[i] = 'a' + ((s[i]-'a' + k[j++]-'a')%26);
                    j %= sz;
                }
            }
            printf("%s", s);
        }
    }
    return 0;
}
