/*
 * Leonardo Deliyannis Constantin
 * URI 2549 - Nomes de Usuários
*/

#include <stdio.h>
#include <ctype.h>
#include <set>
#include <string>
using namespace std;
#define MAX 112

int main(){
    int N, A, i, tam, fancyNames;
    char s[MAX], u[MAX];
    bool wasSpace;
    while(scanf("%d %d ", &N, &A) != EOF){
        set<string> myset;
        fancyNames = 0;
        while(N--){
            fgets(s, MAX, stdin);
            tam = 0;
            wasSpace = true;
            for(i = 0; s[i] != '\n'; i++){
                if(wasSpace && isalpha(s[i])){
                    wasSpace = false;
                    u[tam++] = s[i];
                }
                else if(!wasSpace && s[i] == ' '){
                    wasSpace = true;
                }
            }
            u[tam] = '\0';
            if(myset.count(u)){
                fancyNames++;
            }else{
                myset.insert(u);
            }
        }
        printf("%d\n", fancyNames);
    }
    return 0;
}
