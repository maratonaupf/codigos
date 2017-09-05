/*
 * Leonardo Deliyannis Constantin
 * URI 2650 - Construindo Muralhas
 */

#include <stdio.h>
#include <ctype.h>
#include <string>
using namespace std;

struct titan{
	string name;
	int ht;
};


int main(){
	int N, W, i, j;
	char s[112];
	titan t;
	while(scanf("%d %d ", &N, &W) != EOF){
		for(i = 0; i < N; i++){
			t.name = "";
			t.ht = 0;
			while(scanf("%s ", s), !isdigit(s[0])){
				if(!t.name.empty()) t.name.push_back(' ');
				t.name.append(s);
			}
			for(j = 0; s[j]; j++){
				t.ht *= 10;
				t.ht += s[j] - '0';
			}
			if(t.ht > W){
				printf("%s\n", t.name.c_str());
			}
		}
	}
	return 0;
}
