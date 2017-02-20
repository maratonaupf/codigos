#include<stdio.h>
#include<map>

using namespace std;

typedef map<string, int> msi;

int main(void){
	msi ocorr;
	char aux[50];
	while(scanf("%s", aux) != EOF){
		string s = aux;
		if(ocorr.count(s) == 0){
			ocorr[s] = 1;
		}else{
			ocorr[s]++;
		}
	}
	msi::iterator it;
	for(it = ocorr.begin(); it != ocorr.end(); ++it){
		printf("%d ocorrencia(s) de \"%s\"\n", it->second, it->first.c_str());
	}
	return 0;
}
