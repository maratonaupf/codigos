#include<stdio.h>
#define MAX 404

int isPalindrome(char *s, int end){
	int i;
	int j = end - 5;
	for(i = end - 4; i < end; i++){
		if(s[i] != s[j--]){
			return false;
		}
	}
	return true;
}

int main(void){
	char s[MAX];
	int N;
	int brindes;
	int top;
	
	while(scanf("%d", &N) != EOF){
		brindes = 0;
		top = 4;
		sprintf(s,"FACE");
		
		while(N--){
			for(int i = 0; i < 4; i++){
				getchar();
				scanf("%s", s + top);
				top++;
				//puts(s);
			}
			
			if(isPalindrome(s, top)){
				top -= 8;
				brindes++;
				
			}
			
			if(top == 0){
				top = 4;
				sprintf(s,"FACE");
			}
		}
		printf("%d\n", brindes);
	}
	return 0;
}