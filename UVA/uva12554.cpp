#include<stdio.h>
#include<string.h>
#define MAX 112

int main(void){
	int N, i, person;
	bool p[MAX], done;
	char s[MAX][MAX];
	char song[16][10] = {
		"Happy", "birthday", "to", "you",
		"Happy", "birthday", "to", "you",
		"Happy", "birthday", "to", "Rujia",
		"Happy", "birthday", "to", "you"
	};
	scanf("%d\n", &N);
	for(i = 0; i < N; i++){
		fgets(s[i], MAX, stdin);
		s[i][strlen(s[i])-1] = 0;
	}
	memset(p, 0, sizeof(p));
	person = 0;
	done = false;
	while(!done){
		for(i = 0; i < 16; i++){
			printf("%s: %s\n", s[person], song[i]);
			p[person++] = true;
			person %= N;
		}
		done = true;
		for(i = 0; i < N; i++){
			if(!p[i]){
				done = false;
				break;
			}
		}
	}
	return 0;
}
