/*
 * Leonardo Deliyannis Constantin
 * br.spoj.com/problems/ALIENSMG
 */

#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int main(){
	int N, cont;
	string s;
	set<string> st;
	while(cin >> N, N != 0){
		cont = 0;
		while(N--){
			cin >> s;
			sort(s.begin(), s.end());
			if(!st.count(s)){
				cont++;
				st.insert(s);
			}
		}
		cout << cont << endl;
		st.clear();
	}
	return 0;
}
