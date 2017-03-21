//#include<stdio.h>
#include<iostream>
//#include<stdlib.h>
#include<algorithm>
//#include<string.h>
#include<string> // s.size()
//#include<ctype.h>
#include<cctype> // tolower(c)
#define MAX 1123

using namespace std;
/*
int cmp(const void *p1, const void *p2){
	return strcasecmp((char *) p1, (char *) p2);
}
*/
string minuscula(string s){
	int tam = s.size();
	for(int i = 0; i < tam; i++){
		s[i] = tolower(s[i]);
	}
	return s;
}

bool cmp(string a, string b){
	return minuscula(a) < minuscula(b);
}

int main(void){
	int quant = 0;
	//char str[MAX][82];
	string str[MAX];
	//while(fgets(str[quant], 82, stdin) != NULL){
	while(getline(cin, str[quant])){
		quant++;
	}
	//qsort(str, quant, sizeof(str[0]), cmpstringp);
	sort(&str[0], &str[quant], cmp);
	//printf("%s", str[quant-1]);
	cout << str[quant-1] << endl;
	return 0;
}
