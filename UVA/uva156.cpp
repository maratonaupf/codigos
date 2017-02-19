#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

// converte a string para minuscula e ordena suas letras
string anagramize(string s){
	int i, tam = (int)s.size();
	for(i = 0; i < tam; i++){
		if(isupper(s[i])) s[i] = tolower(s[i]);
	}
	sort(s.begin(), s.end());
	return s;
}

int main(void){
	vector<string> v;
	map<string, int> m;
	string s, aux;
	while(cin >> s, s != "#"){
		v.push_back(s);
		aux = anagramize(s);
		if(m.count(aux) == 0) m[aux] = 1;
		else m[aux]++;
	}
	sort(v.begin(), v.end());
	for(auto it = v.begin(); it != v.end(); ++it){
		if(m[anagramize(*it)] == 1){
			cout << *it << endl;
		}
	}
	v.clear();
	return 0;
}
