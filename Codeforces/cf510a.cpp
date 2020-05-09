/*
 * Leonardo Deliyannis Constantin
 * https://codeforces.com/problemset/problem/510/A
*/

#include<bits/stdc++.h>
using namespace std;
#define MAX 51

int main(){
    char s[MAX][MAX];
    int n, m;
    int r;
    while(cin >> n >> m){
        memset(s, '.', sizeof(s));
        for(r = 0; r < n; r++){
            if(r % 2 == 0)
                memset(s[r], '#', sizeof(s[r]));
            if(r % 4 == 1)
                s[r][m-1] = '#';
            if(r % 4 == 3)
                s[r][0] = '#';
            s[r][m] = '\0';
            cout << (string)s[r] << "\n";
        }
    }
    return 0;
}
