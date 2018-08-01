/*
 * Leonardo Deliyannis Constantin
 * TAP 2013 E - Escaping from escaping
*/

#include <stdio.h>
#include <string.h>
#include <string>
#include <set>
using namespace std;
#define MAX 112345
#define LOG_MAX 20

int main(){
    int T, N, limit, sz, i;
    char s[MAX];
    scanf("%d", &T);
    while(T--){
        scanf(" %s", s);
        N = strlen(s);
        limit = min(LOG_MAX, N);
        for(sz = 1; sz <= limit; sz++){
            set<string> st;
            for(i = 0; i <= N-sz; i++){
                st.insert(string(s+i, sz));
            }
            if((int)st.size() < (1 << sz)){
                printf("%d\n", sz);
                break;
            }
        }
    }
    return 0;
}
