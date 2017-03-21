#include<stdio.h>

int team(char c){
	return (c == 'R') ? 0 : (c == 'G') ? 1 : 2;
}

int value(char M, char S){
	return ((M == 'R' && S == 'G') ||
		(M == 'G' && S == 'B') ||
		(M == 'B' && S == 'R')) ? 2 : 1;
}

const char str[5][10] = { "red", "green", "blue", "empate", "trempate" };

int res(int sc[]){
	return (sc[0] > sc[1] && sc[0] > sc[2]) ? 0 :
		(sc[0] < sc[1] && sc[1] > sc[2]) ? 1 :
		(sc[0] < sc[2] && sc[1] < sc[2]) ? 2 :
		(sc[0] == sc[1] && sc[1] == sc[2]) ? 4 : 3;
}

int main(void){
	int C, P, sc[3];
	char M, S;
	scanf("%d", &C);
	while(C--){
		scanf("%d", &P);
		sc[0] = sc[1] = sc[2] = 0;
		while(P--){
			scanf(" %c %c", &M, &S);
			sc[team(M)] += value(M, S);
		}
		puts(str[res(sc)]);
	}
	return 0;
}
