/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/problemset/problem/339/A
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 112

int main(){
    char s[MAX];
    int i, sz;
    while(scanf("%s ", s) != EOF){
        vector<int> v;
        sz = (int)strlen(s);
        for(i = 0; i < sz; i += 2){
            v.push_back(s[i] - '0');
        }
        sort(v.begin(), v.end());
        for(i = 0; i < (int)v.size(); i++){
            printf("%d%c", v[i], i < (int)v.size()-1 ? '+' : '\n');
        }
    }
    return 0;
}
