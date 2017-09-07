/*
 * Leonardo Deliyannis Constantin
 * codigo
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <string>
#include <vector>
#include <map>
using namespace std;
#define LEN 31

const char line[] = 
	"---------------------------------------------------------\n";
const string dontEncode = "AEIOUYWH";

map<char, int> code;
void setCodes(){
	int i, j;
	string mask[] = {
		"BPFV", "CSXZ", "KGJQ", "DT", "L", "MN", "R"
	};
	for(i = 0; i < 7; i++){
		for(j = 0; j < (int)mask[i].size(); j++){
			code[mask[i][j]] = i+1;
		}
	}
}

inline bool encodable(int c){
	for(int i = 0; dontEncode[i]; i++){
		if(dontEncode[i] == c) return false; }
	return true;
}

string encode(const string &s){
	int i;
	string ret;
	ret.push_back(s[0]);
	for(i = 1; s[i+1]; i++){
		if(!encodable(s[i]) || code[s[i-1]] == code[s[i]]){
			//ret.push_back('0');
			continue;
		}
		ret.push_back('0' + code[s[i]]);
	}
	while((int)ret.size() < (int)s.size() - 1)
		ret.push_back('0');
	ret.push_back(s[i]);
	return ret;
}

inline void prettyPrint(const char *n, const char *t){
	int tam = strlen(n);
	printf("         %s", n);
	printf("%*s%s\n", 25 - tam, "", t);
}

int main(){
	char s[LEN];
	setCodes();
	prettyPrint("NOME", "CODIGO LOUCO DO ROBERTO");
	printf(line);
	while(fgets(s, LEN, stdin) != NULL){
		s[strlen(s)-1] = 0;
		prettyPrint(s, encode(s).c_str());
	}
	printf("                   FIM DO PROGRAMA\n");
	return 0;
}
