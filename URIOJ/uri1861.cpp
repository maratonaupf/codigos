/*
 * Leonardo Deliyannis Constantin
 * URI 1861 - O Hall dos Assassinos
*/

#include <stdio.h>
#include <map>
#include <string>
using namespace std;
#define LEN 12

int main(){
    char s[LEN], t[LEN];
    map<string, int> murders;
    map<string, bool> dead;
    while(scanf("%s %s", s, t) != EOF){
        if(!dead[s]){
            murders[s]++;
        }
        if(!dead[t]){
            dead[t] = true;
            murders.erase(t);
        }
    }
    printf("HALL OF MURDERERS\n");
    for(auto it = murders.begin(); it != murders.end(); ++it){
        printf("%s %d\n", it->first.c_str(), it->second);
    }
    return 0;
}
