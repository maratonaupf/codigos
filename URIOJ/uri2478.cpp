/*
 * Leonardo Deliyannis Constantin
 * URI 2478 - Acerte o Presente
*/

#include <stdio.h>
#include <string>
#include <map>
#include <set>
using namespace std;
#define LEN 112

int main(){
    int N, j;
    char s[LEN], t[LEN];
    scanf("%d", &N);
    map<string, set<string> > mymap;
    while(N--){
        scanf(" %s", s);
        for(j = 0; j < 3; j++){
            scanf(" %s", t);
            mymap[s].insert(t);
        }
    }
    while(scanf(" %s %s", s, t) != EOF){
        if(mymap[s].count(t))
            printf("Uhul! Seu amigo secreto vai adorar o/\n");
        else
            printf("Tente Novamente!\n");
    }
    return 0;
}
