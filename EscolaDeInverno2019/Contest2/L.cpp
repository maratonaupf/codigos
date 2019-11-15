#include<stdio.h>
#include<map>
using namespace std;
#define MAX 112345

int main(){
    int sz;
    char s[MAX], t[MAX];
    while(scanf("%s ", s) != EOF){
        map<char, int> cnt;
        for(int i = 0; s[i]; i++){
            cnt[s[i]]++;
        }
        for(char c = 'a'; c < 'z'; c++){
            cnt[c+1] += cnt[c]/2;
            cnt[c] %= 2;
        }
        sz = 0;
        for(char c = 'z'; c >= 'a'; c--){
            while(cnt[c]--){
                t[sz++] = c;
            }
        }
        t[sz] = '\0';
        printf("%s\n", t);
    }
    return 0;
}
