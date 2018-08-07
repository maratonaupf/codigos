/*
 * Leonardo Deliyannis Constantin
 * URI 1449 - O Fantástico Jaspion
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <string>
#include <unordered_map>
using namespace std;
#define LEN 82

int main(){
    int T, M, N;
    char s[LEN], t[LEN];
    scanf("%d", &T);
    while(T--){
        scanf("%d %d ", &M, &N);
        unordered_map<string, string> tl;
        while(M--){
            fgets(s, LEN, stdin);
            fgets(t, LEN, stdin);
            s[strlen(s)-1] = 0;
            t[strlen(t)-1] = 0;
            tl[s] = t;
        }
        while(N--){
            fgets(s, LEN, stdin);
            int sz = 0;
            for(int i = 0; s[i]; i++){
                if(isalpha(s[i]))
                    t[sz++] = s[i];
                else{
                    t[sz] = 0;
                    sz = 0;
                    printf("%s%c", tl.count(t) ? tl[t].c_str() : t, s[i]);
                } 
            }
        }
        printf("\n");
    }
    return 0;
}
