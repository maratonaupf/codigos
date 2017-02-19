#include<stdio.h>
#include<string.h>

int main(void){
	int N, i;
	char s[36];
	strcpy(s, "LIFE IS NOT A PROBLEM TO BE SOLVED");
	while(scanf("%d", &N) != EOF){
		for(i=0; i<N; i++)
			putchar(s[i]);
		putchar('\n');
	}
	return 0;
}
