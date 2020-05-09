/*
 * Leonardo Deliyannis Constantin
 * https://codeforces.com/problemset/problem/155/A
*/

#include<bits/stdc++.h>
using namespace std;
#define MAX 1123

int main(){
    int n, i;
    int p[MAX]; 
    int highest, lowest, answer;
    while(cin >> n){
        cin >> p[0];
        highest = p[0];
        lowest = p[0];
        answer = 0;
        for(i = 1; i < n; i++){
            cin >> p[i];
            if(p[i] < lowest){
                lowest = p[i];
                answer += 1;
            }
            if(p[i] > highest){
                highest = p[i];
                answer += 1;
            }
        }
        cout << answer << "\n";
    }
    return 0;
}
