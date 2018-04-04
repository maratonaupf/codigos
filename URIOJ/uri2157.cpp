/*
 * Leonardo Deliyannis Constantin
 * URI 2157 - Sequência Espelho
*/

#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int C, B, E;
    char buf[12];
    scanf("%d", &C);
    while(C--){
        string s;
        scanf("%d %d", &B, &E);
        for(int i = B; i <= E; i++){
            sprintf(buf, "%d", i);
            s.append(buf);
        }
        printf("%s", s.c_str());
        reverse(s.begin(), s.end());
        printf("%s\n", s.c_str());
    }
    return 0;
}
