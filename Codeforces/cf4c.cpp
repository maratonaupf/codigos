/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/problemset/problem/4/C
*/

#include <stdio.h>
#include <string>
#include <map>
using namespace std;
#define LEN 42

int main(){
    int n;
    char s[LEN];
    while(scanf("%d", &n) != EOF){
        map<string, int> cnt;
        while(n--){
            scanf(" %s", s);
            if(cnt[s] == 0)
                printf("OK\n");
            else
                printf("%s%d\n", s, cnt[s]);
            cnt[s]++;
        }
    }
    return 0;
}
