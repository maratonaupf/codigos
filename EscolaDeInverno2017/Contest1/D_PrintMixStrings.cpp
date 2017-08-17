/*
 * Leonardo Deliyannis Constantin
 * D - Print Mix Strings
 */

#include <stdio.h>
#include <string>
#include <set>
using namespace std;
typedef unsigned uns;

string a, b;
set<string> tree;

void generate(uns i, uns j, string res){
	if(i == a.size() && j == b.size()){
		tree.insert(res);
	}
	else{
		if(i < a.size()) generate(i+1, j, res+a[i]);
		if(j < b.size()) generate(i, j+1, res+b[j]);
	}
}

int main(){
	int T;
	char s1[11], s2[11];
	scanf("%d\n", &T);
	while(T--){
		scanf("%s %s\n", s1, s2);
		a = s1;
		b = s2;
		generate(0, 0, string(""));
		for(auto it = tree.begin(); it != tree.end(); ++it){
			printf("%s\n", it->c_str());
		}
		tree.clear();
		printf("\n");
	}
	return 0;
}
