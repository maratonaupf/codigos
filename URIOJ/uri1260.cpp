#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<map>

using namespace std;

typedef map<string, int> mapsi;
mapsi m;

int main(void){	
	int N, all;
	string s;
	scanf("%d", &N);
	getchar();
	getline(cin, s);
	while(N--){ 
		all = 0;
		//getchar();
		while(getline(cin, s), s[0]){
			if(m.count(s)) m[s]++;
			else m[s] = 1;
			all++;
		}
		
		for(mapsi::iterator it=m.begin(); it!=m.end(); ++it)
			printf("%s %.4lf\n", it->first.c_str(), (double) (it->second * 100.0) / all);
			
		m.clear();
		if(N) putchar('\n');
	}
	return 0;
}
