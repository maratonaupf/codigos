#include<iostream>
#include<sstream>
#include<string>

using namespace std;

void decipher(string s){
	string aux;
	stringstream ss(s);
	while(ss >> aux)
		cout << aux[0];
	cout << endl;
}

int main(void){	
	int T;
	string s;
	cin >> T;
	getline(cin, s);
	while(T--){		
		getline(cin, s);
		decipher(s);
	}
	return 0;
}
