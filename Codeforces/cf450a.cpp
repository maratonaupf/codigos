/*
 * Leonardo Deliyannis Constantin
 * https://codeforces.com/problemset/problem/450/A
*/

#include<bits/stdc++.h>
using namespace std;
#define MAX 101

int main(){
    int n, m;
    int a[MAX];
    while(cin >> n >> m){
        queue<int> q;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            q.push(i);
        }
        int last;
        while(!q.empty()){
            int child = q.front();
            q.pop();
            a[child] -= m;
            if(a[child] > 0)
                q.push(child);
            else
                last = child;
        }
        cout << last << "\n";
    }
    return 0;
}
