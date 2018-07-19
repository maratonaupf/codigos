/*
 * Leonardo Deliyannis Constantin
 * URI 1876 - Rabiola
*/

#include <stdio.h>
#include <algorithm>
using namespace std;
#define LEN 112

int main(){
    char s[LEN];
    bool openX;
    int sz, ans, i;
    while(fgets(s, LEN, stdin) != NULL){
        openX = false;
        sz = ans = 0;
        for(i = 0; s[i] != '\n'; i++){
            if(s[i] == 'o') sz++;
            if(s[i] == 'x'){
                if(openX) sz /= 2;
                openX = true;
                ans = max(ans, sz);
                sz = 0;
            }
        }
        ans = max(ans, sz);
        printf("%d\n", ans);
    }
    return 0;
}
