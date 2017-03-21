#include<stdio.h>
#include<map>
#define MAX 212

using namespace std;

map<char, int> freq;
void setmap(){
	char id[] = "WHQESTX";
	for(int i = 0; i < 7; i++){
		freq[id[i]] = 64 >> i;
	}
}

int main(void){
	char s[MAX];
	int dur, cont;
	setmap();
	while(fgets(s, MAX, stdin), s[0] != '*'){
		dur = cont = 0;
		for(int i = 1; s[i] != '\n'; i++){
			if(s[i] == '/'){
				if(dur == 64) cont++;
				dur = 0;
			}
			else dur += freq[s[i]];
		}
		printf("%d\n", cont);
	}
	return 0;
}
