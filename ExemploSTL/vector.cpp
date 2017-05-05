#include <stdio.h>
#include <string.h>
#include <vector>
#include <string>
using namespace std;

int main(){
	int tam;
	int N;
	string s;
	char cs[82];
	scanf("%d\n", &N);
	fgets(cs, 82, stdin);
	cs[strlen(cs) - 1] = '\0';
	s = cs;
	vector<string> v(N, s);
	tam = v.size();
	for(int i = 0; i < tam; i++){
		printf("%s\n", v[i].c_str());
	}

	return 0;
}
