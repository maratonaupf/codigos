/*
 * Leonardo Deliyannis Constantin
 * http://br.spoj.com/problems/BRACELMG/
 */

#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;
#define LEN 11234

int main(){
	int T;
	char buf[LEN];
	string p, r, s;
	bool found;
	scanf("%d\n", &T);
	while(T--){
		scanf("%s ",  buf); p = buf;
		scanf("%s\n", buf); s = buf;
		s += s;
		r = p;
		reverse(r.begin(), r.end());
		found = s.find(p) != string::npos || s.find(r) != string::npos;
		printf("%c\n", found ? 'S' : 'N');
	}
	return 0;
}
