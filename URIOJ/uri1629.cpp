#include<stdio.h>
#include<string.h>
#define MAX 1123

int main(void){
	int N, zeros, ones, digit;
	char s[MAX];
	while(scanf("%d", &N), N){
		while(N--){
			scanf("%s", s);
			
			zeros = 0;
			ones = 0;
			
			for(int i = 0; s[i]; i++){
				if(i & 1){
					ones += s[i] - '0';
				}
				else{
					zeros += s[i] - '0';
				}
			}
			
			digit = 0;
			while(zeros){
				digit += zeros % 10;
				zeros /= 10;
			}
			while(ones){
				digit += ones % 10;
				ones /= 10;
			}
			printf("%d\n", digit);
		}
	}
	return 0;
}