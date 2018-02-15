/*
 * Leonardo Deliyannis Constantin
 * URI 2486 - C Mais ou Menos?
 */

#include <stdio.h>
#include <string.h>
#include <map>
#include <string>
using namespace std;
#define LEN 22 

map<string, int> m;
void setup(){
	m["suco de laranja"] = 120;
	m["morango fresco"] = 85;
	m["mamao"] = 85;
	m["goiaba vermelha"] = 70;
	m["manga"] = 56;
	m["laranja"] = 50;
	m["brocolis"] = 34;
}

int main(){
	int T, N, cons;
	char s[LEN];
	setup();
	while(scanf("%d", &T), T != 0){
		cons = 0;
		while(T--){
			scanf("%d ", &N);
			fgets(s, LEN, stdin);
			s[strlen(s)-1] = 0;
			cons += m[s] * N;
		}
		if(cons < 110) 
			printf("Mais %d mg\n", 110 - cons);
		else if(cons <= 130) 
			printf("%d mg\n", cons);
		else 
			printf("Menos %d mg\n", cons - 130);
	}
	return 0;
}
