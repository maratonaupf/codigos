#include<stdio.h>
#include<ctype.h>
#define MAX 112345

char s[MAX];

int main(){
	int i, c;
	while(fgets(s, MAX, stdin) != NULL){
		c = 0;
		for(i = 0; s[i] != '\n'; i++){
			if(isupper(s[i]) && islower(s[i+1])) c++;
		}
		printf("%d\n", c);
	}
	return 0;
}
