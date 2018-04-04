/*
 * Leonardo Deliyannis Constantin
 * URI 1278 - Justificador II
*/

#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define LEN 52

typedef vector<string> vs;

int main(){
    int N, l, i, tam, maxSize;
    bool wasLetter, firstCase = true;
    char s[LEN], word[LEN];
    while(scanf(" %d ", &N), N != 0){
        firstCase ? firstCase = false : printf("\n");
        vector<vs> v(N, vs());
        vector<int> lineSize(N, 0);
        maxSize = 0;
        for(l = 0; l < N; l++){
            fgets(s, LEN, stdin);
            tam = 0;
            wasLetter = false;
            for(i = 0; s[i]; i++){
                if(isalpha(s[i])){
                    if(!wasLetter)
                        wasLetter = true;
                    word[tam++] = s[i];
                }
                else if(wasLetter){
                    word[tam] = '\0';
                    lineSize[l] += tam + !v[l].empty();
                    v[l].push_back(word);
                    wasLetter = false;
                    tam = 0;
                }
            }
            maxSize = max(maxSize, lineSize[l]);
        }
        for(l = 0; l < N; l++){
            printf("%*s", maxSize - lineSize[l], "");
            for(i = 0; i < (int)v[l].size(); i++){
                printf("%s%c", v[l][i].c_str(), 
                    i < (int)v[l].size() - 1 ? ' ' : '\n');
            }
        }
    }
    return 0;
}
