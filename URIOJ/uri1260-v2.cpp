/*
 * Leonardo Deliyannis Constantin
 * https://www.urionlinejudge.com.br/judge/pt/problems/view/1260
 */

#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

int main(){
	int T;
	string s;
	cin >> T;
	cin.ignore();
	cin.ignore();
	while(T--){
		map<string, int> m;
		map<string, int>::iterator it;
		int count = 0;
		while(getline(cin, s), s != ""){
			m[s]++;
			count++;
		}
		for(it = m.begin(); it != m.end(); ++it){
			cout << it->first << " ";
			cout << fixed << setprecision(4);
			cout << ((double) it->second * 100.0  / (double) count) << endl;
		}
		if(T > 0) cout << endl;
	}
	return 0;
}