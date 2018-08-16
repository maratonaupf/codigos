/*
 * Leonardo Deliyannis Constantin
 * URI 2678 - Discagem de Voz
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 312

char table[256];

void setup(){
    memset(table, 0, sizeof table);
    char conj[8][5] = {
        "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ" };
    for(int i = 0; i < 8; i++){
        for(int j = 0; conj[i][j]; j++){
            table[(int)conj[i][j]] = 
            table[tolower(conj[i][j])] = '2' + i;
        }
    }
    for(int c = '0'; c <= '9'; c++)
        table[c] = c;
    table['*'] = '*';
    table['#'] = '#';
}

int main(){
    char s[MAX], t[MAX];
    int i, sz;
    setup();
    while(fgets(s, MAX, stdin) != NULL){
        sz = 0;
        for(i = 0; s[i]; i++){
            if(table[(int)s[i]] != 0){
                t[sz++] = table[(int)s[i]];
            }
        }
        t[sz] = 0;
        printf("%s\n", t);
    }
    return 0;
}
