#include<stdio.h>
#include<string.h>
#define MAX 26

int main(void){
	int word[MAX];
	int R, c, let, wrong, right;
	int status; // 0 = chickened out, -1 = lose, 1 = win
	while(scanf("%d\n", &R), R != -1){
		memset(word, 0, sizeof(word));
		let = 0;
		while((c = getchar()) != '\n'){
			c-='a';
			if(word[c] == 0){
				word[c] = 1; // exists in word
				let++;
			}
		}
		wrong = status = right = 0;
		while((c = getchar()) != '\n'){
			c-='a';
			if(word[c] == 0){ // inexists, not guessed yet
				word[c] = -1;
				wrong++;
				if(wrong == 7 && status == 0) status = -1;
			}
			if(word[c] == 1){ // exists, not guessed yet
				word[c] = 2; // exists, already guessed
				right++;
				if(right == let && status == 0) status = 1;
			}
		}
		printf("Round %d\n", R);
		printf("You %s.\n", status == 0 ? "chickened out" :
			status == 1 ? "win" : "lose");
	}
	return 0;
}
