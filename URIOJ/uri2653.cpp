/*
 * Leonardo Deliyannis Constantin
 * URI 2653 - Dijkstra
 * [nada a ver com o nome]
*/

#include<iostream>
#include<string>
#include<set>
using namespace std;

int main(){
    set<string> myset;
    string s;
    while(getline(cin, s)){
        myset.insert(s);
    }
    cout << myset.size() << endl;
    myset.clear();
    return 0;
}
