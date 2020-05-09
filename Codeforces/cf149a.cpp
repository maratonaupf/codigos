/*
 * Leonardo Deliyannis Constantin
 * https://codeforces.com/problemset/problem/149/A
*/

#include<bits/stdc++.h>
using namespace std;

bool comp(int a, int b){
    return a > b;
}

int main(){
    const int n = 12;
    int k, sum;
    int i, a[n];
    while(cin >> k){
        for(i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a, a+n, comp);
        sum = 0;
        i = 0;
        while(sum < k){
            if(i == n)
                break;
            sum += a[i];
            i++;
        }
        if(sum >= k){
            cout << i << "\n";
        }
        else{
            cout << "-1\n";
        }
    }
    return 0;
}
