/*
 * Leonardo Deliyannis Constantin
 * URI 2502 - Decifrando a Carta Criptografada
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unordered_map>
using namespace std;
#define MAX  1123
#define MAXC 24

unordered_map<char, char> mymap;

void setup(const char *c1, const char *c2){
    mymap.clear();
    for(int i = 0; c1[i]; i++){
        mymap[toupper(c1[i])] = toupper(c2[i]);
        mymap[toupper(c2[i])] = toupper(c1[i]);
        mymap[tolower(c1[i])] = tolower(c2[i]);
        mymap[tolower(c2[i])] = tolower(c1[i]);
    }
}

void decrypt(char *s){
    for(int i = 0; s[i] != '\n'; i++){
        if(mymap.count(s[i])){
            s[i] = mymap[s[i]];
        }
    }
}

int main(){
    int C, N;
    char c1[MAXC], c2[MAXC];
    char s[MAX];
    while(scanf("%d %d ", &C, &N) != EOF){
        fgets(c1, MAXC, stdin);
        fgets(c2, MAXC, stdin);
        c1[C] = c2[C] = '\0';
        setup(c1, c2);
        while(N--){
            fgets(s, MAX, stdin);
            decrypt(s);
            printf("%s", s);
        }
        printf("\n");
    }
    return 0;
}
