/*
 * Leonardo Deliyannis Constantin
 * https://www.urionlinejudge.com.br/judge/pt/problems/view/2136
 */

#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

struct convidado{
	string s;
	bool amigo;
	convidado(string _s, string _a){
		s = _s; 
		amigo = (_a[0] == 'Y');
	}
	bool operator <(const convidado& outro) const{
		if(amigo == outro.amigo) return s < outro.s;
		return (amigo && !outro.amigo);
	}
};

int main(){
	string s, amigo, escolhido = "";
	set<convidado> st;
	set<convidado>::iterator it;
	while(cin >> s, s != "FIM"){
		cin >> amigo;
		st.insert(convidado(s, amigo));
		if(amigo[0] == 'Y' && escolhido.size() < s.size()){
			escolhido = s;
		}
	}
	for(it = st.begin(); it != st.end(); ++it){
		cout << it->s << endl;
	}
	cout << "\nAmigo do Habay:\n" << escolhido << endl;
	return 0;
}
