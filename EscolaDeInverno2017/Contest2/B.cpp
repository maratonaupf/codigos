/*
 * Leonardo Deliyannis Constantin
 * B - Poodle
 */

#include <stdio.h>
#include <string>
using namespace std;

string geraPoodle(int tam){
	string ret = "P";
	while((int)ret.size() < tam-3){
		ret.push_back('o');
	}
	ret += "dle";
	return ret;
}

int main(){
	int N, P;
	while(scanf("%d %d", &N, &P), N != 0){
		int aux = N/P;
		if(N%P != 0) aux++;
		if(aux < 6) aux = 6;
		else if(aux > 20) aux = 20;
		printf("%s\n", geraPoodle(aux).c_str());
	}
	return 0;
}
