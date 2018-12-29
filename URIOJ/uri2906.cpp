/*
 * Leonardo Deliyannis Constantin
 * URI 2906 - Database of Clients
*/

#include <stdio.h>
#include <string>
#include <set>
using namespace std;
#define MAX 112

int main(){
    int N, i, sz;
    char m[MAX];
    char u[MAX];
    while(scanf("%d ", &N) != EOF){
        set<string> users;
        while(N--){
            fgets(m, MAX, stdin);
            sz = 0;
            for(i = 0; m[i] != '+' && m[i] != '@'; i++){
                if(m[i] != '.')
                    u[sz++] = m[i];
            }
            u[sz++] = '@';
            for(; m[i-1] != '@'; i++);
            for(; m[i]; i++){
                u[sz++] = m[i];
            }
            u[sz] = 0;
            users.insert(u);
        }
        printf("%d\n", (int)users.size());
    }
    return 0;
}
