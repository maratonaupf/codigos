/*
 * Leonardo Deliyannis Constantin
 * Google Code Jam 2020 - Problem: Nesting Depth
*/

#include<bits/stdc++.h>
using namespace std;
#define MAX 112

int main(){
    int t, x, i, start;
    char c, aux[MAX];
    string s;
    scanf("%d", &t);
    for(x = 1; x <= t; x++){
        scanf(" %s", aux);
        s = aux;
        s.push_back('0');
        for(c = '1'; c <= '9'; c++){
            start = -1;
            for(i = 0; s[i]; i++){
                if(s[i] >= c && start == -1){
                    start = i;
                }
                if(s[i] < c && start != -1){
                    s.insert(s.begin()+start, '(');
                    s.insert(s.begin()+i+1, ')');
                    start = -1;
                    i += 2;
                }
            }
        }
        s.pop_back();
        printf("Case #%d: %s\n", x, s.c_str());
    }
    return 0;
}
