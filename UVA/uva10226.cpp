#include<stdio.h>
#include<string.h>
#include<string>
#include<map>
#define LEN 32
using namespace std;

int main(void){
	int T;
	double quant;
	char s[LEN];
	scanf("%d\n\n", &T);
	while(T--){
		map<string, int> m;
		quant = 0.0;
		while(fgets(s, LEN, stdin) != NULL && strcmp(s, "\n")){
			s[strlen(s)-1] = 0;
			m[(string)s]++;
			quant += 1.0;
		}
		map<string, int>::iterator it;
		for(it = m.begin(); it != m.end(); ++it){
			printf("%s %.4lf\n", it->first.c_str(), 
				((double) it->second) * 100.0 / quant);
		}
		if(T) printf("\n");
	}
	return 0;
}
