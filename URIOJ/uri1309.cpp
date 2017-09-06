/*
 * Leonardo Deliyannis Constantin 
 * URI 1309 - Formatação Monetária
*/

#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;

string toString(int d){
	int pushed = 0;
	string ret = "";
	do {
		if(pushed > 0 && pushed % 3 == 0)
			ret.push_back(',');
		ret.push_back('0' + (d % 10));
		d /= 10;
		pushed++;
	} while(d > 0);
	reverse(ret.begin(), ret.end());
	return ret;
}

string format(int d, int c){
	int i, tam;
	string s = "$";
	string n = toString(d);
	tam = (int)n.size();
	for(i = 0; i < tam; i++){
		s.push_back(n[i]);
	}
	s.push_back('.');
	if(c < 10)
		s.push_back('0');
	s.append(toString(c));
	return s;
}

int main(){
	int d, c;
	while(scanf(" %d", &d) != EOF){
		scanf(" %d", &c);
		printf("%s\n", format(d, c).c_str());
	}
	return 0;
}
