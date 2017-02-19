#include<stdio.h>
#include<string.h>
#include<algorithm>
#define MAX 52
using namespace std;

int main(void){
	char s[MAX];
	while(fgets(s, MAX, stdin), s[0] != '#'){
		if(next_permutation(s, s + strlen(s) - 1)){
			printf("%s", s);
		}
		else printf("No Successor\n");
	}
	return 0;
}
