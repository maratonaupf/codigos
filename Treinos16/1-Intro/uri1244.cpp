//#include<stdio.h>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<vector>
#define MAX 51
//#define DEBP // DEBug Print

using namespace std;

bool cmp(string a, string b){
	return a.size() > b.size();
}

int main(void){
	int N;
	vector<string> v;
	v.reserve(MAX);
	//char s[MAX];
	string str, s;
	//scanf("%d", &N);
	cin >> N;
	cin.ignore();
	while(N-- > 0){
		getline(cin, str);
#ifdef DEBP
		cout << "DEBUG: " << str << endl;
#endif
		istringstream iss(str);
		while(iss >> s){
			v.push_back(s);
		}
		stable_sort(v.begin(), v.end(), cmp);
		
		for(unsigned i = 0; i < v.size(); i++){
			//printf("%s%c", v[i].c_str(), i < tam-1? ' ' : '\n');
			cout << v[i];
			if(i < v.size()-1){
				cout << " ";
			}else{
				cout << endl;
			}
		}
		v.clear();
	}
	return 0;
}
