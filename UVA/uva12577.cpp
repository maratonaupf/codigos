#include<stdio.h>
#include<string.h>

int main(void){
	char s[10];
	int cn = 0;
	while(scanf("%s", s), strcmp(s, "*")){
		getchar();
		printf("Case %d: Hajj-e-%s\n", ++cn, s[0] == 'H' ? "Akbar" : "Asghar");
	}
	return 0;
}
