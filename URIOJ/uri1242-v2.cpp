/*
 * Leonardo Deliyannis Constantin
 * URI 1242 - Ácido Ribonucleico Alienígena
*/ 

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

bool match(char a, char b){
    if(a > b) swap(a, b);
    return (a == 'B' && b == 'S') || (a == 'C' && b == 'F');
}

int main(){
    string acid;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> acid){
        stack<char> st;
        int cnt = 0;
        for(int i = 0; i < (int)acid.size(); i++){
            if(!st.empty() && match(st.top(), acid[i])){
                st.pop();
                cnt++;
            }
            else{
                st.push(acid[i]);
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
