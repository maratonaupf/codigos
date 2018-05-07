/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/contest/977/problem/B
*/

#include <stdio.h>
#include <string>
#include <map>
using namespace std;
#define MAX 26
#define LEN 112

int main(){
    int N, i;
    char s[LEN];
    string ans, curr;
    while(scanf("%d", &N) != EOF){
        scanf("%s", s);
        map<string, int> f;
        ans = "";
        for(i = 0; s[i+1]; i++){
            f[curr = string(s+i, 2)]++;
            if(f[curr] > f[ans])
                ans = curr;
        }
        printf("%s\n", ans.c_str());
    }
    return 0;
}
