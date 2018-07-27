/*
 * Leonardo Deliyannis Constantin
 * URI 1084 - Apagando e Ganhando
*/

#include <stdio.h>
#include <string>
using namespace std;
#define MAX 112345

int main(){
    int N, D, i;
    char n[MAX];
    string s;
    while(scanf("%d %d ", &N, &D), N != 0){
        scanf("%s", n);
        s = "";
        for(i = 0; n[i]; i++){;
            while(!s.empty() && s.back() < n[i] && D > 0){
                s.pop_back();
                D--;
            }
            s.push_back(n[i]);
        }
        while(!s.empty() && D > 0){
            s.pop_back();
            D--;
        }
        printf("%s\n", s.c_str());
    }
    return 0;
}
