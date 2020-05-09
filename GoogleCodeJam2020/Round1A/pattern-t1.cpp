/*
 * Leonardo Deliyannis Constantin
 * Google Code Jam 2020, Round 1A - Pattern Matching
 * Practice submission
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define LEN 112

int main(){
    int t, x, n;
    int i, j;
    char aux[LEN];
    vector<string> v;
    scanf("%d", &t);
    for(x = 1; x <= t; x++){
        scanf("%d", &n);
        string l = "";
        for(i = 0; i < n; i++){
            scanf(" %s", aux);
            v.push_back(aux);
            if(v[i].size() > l.size())
                l = aux;
        }
        string ans = l.substr(1, l.size()-1);
        for(string s : v){
            i = (int)l.size() - 1;
            j = (int)s.size() - 1;
            while(j >= 0){
                if(s[j] == '*') break;
                if(s[j] != l[i]){
                    ans = '*';
                }
                i--;
                j--;
            }
        }
        printf("Case #%d: %s\n", x, ans.c_str());
        v.clear();
    }
    return 0;
}
