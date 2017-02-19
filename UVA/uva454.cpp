#include<iostream>
#include<string>
#include<cctype>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

// deixe só as letras, converta para minusculas e ordene-as
string anagramize(string s){
	unsigned i, tam = s.size();
	for(i = 0; i < tam; i++){
		if(s[i] == ' '){
			s.erase(s.begin() + i);
			tam--;
			i--;
		}
	}
	sort(s.begin(), s.end());
	return s;
}

int main(void){
	int T;
	cin >> T;
	cin.ignore(2, EOF);
	while(T--){
		string s;
		vector<string> words;
		map<string, string> m;
		while(getline(cin, s), s != ""){
			words.push_back(s);
			m[s] = anagramize(s);
		}
		sort(words.begin(), words.end());
		int N = words.size();
		for(int i = 0; i < N; i++){
			for(int j = i+1; j < N; j++){
				if(m[words[i]] == m[words[j]]){
					cout << words[i] << " = " << words[j] << endl;
				}
			}
		}
		if(T) cout << endl;
	}
	return 0;
}
