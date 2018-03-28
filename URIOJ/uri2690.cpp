/*
 * Leonardo Deliyannis Constantin
 * URI 2690 - Nova Senha RA
*/

#include <stdio.h>
#include <ctype.h>
#include <unordered_map>
using namespace std;
#define MAX 212

unordered_map<char, char> mymap;

void setup(){
    const char pat[10][7] = {
        "GQaku", "ISblv", "EOYcmw", "FPZdnx", "JTeoy",
        "DNXfpz", "AKUgq", "CMWhr", "BLVis", "HRjt"
    };
    for(int i = 0; i < 10; i++){
        for(int j = 0; pat[i][j]; j++){
            mymap[pat[i][j]] = '0' + i;
        }
    }
}

int main(){
    int N, i, tam;
    char s[MAX];
    char p[13];
    setup();
    scanf("%d ", &N);
    while(N--){
        fgets(s, MAX, stdin);
        for(i = tam = 0; s[i] != '\n' && tam < 12; i++){
            if(isalpha(s[i])){
                p[tam++] = mymap[s[i]];
            }
        }
        p[12] = '\0';
        printf("%s\n", p);
    }
    return 0;
}
