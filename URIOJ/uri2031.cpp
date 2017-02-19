#include<stdio.h>
#include<string.h>

char results[5][20];
int matchup[3][3];

void setup(){
	strcpy(results[0], "Sem ganhador");
	strcpy(results[1], "Jogador 1 venceu");
	strcpy(results[2], "Jogador 2 venceu");
	strcpy(results[3], "Ambos venceram");
	strcpy(results[4], "Aniquilacao mutua");
	
	matchup[0][0] = 3;
	matchup[1][1] = 0;
	matchup[2][2] = 4;
	
	matchup[1][0] = 1;
	matchup[2][0] = 1;
	matchup[2][1] = 1;
	
	matchup[0][1] = 2;
	matchup[0][2] = 2;
	matchup[1][2] = 2;
}

int valueOf(char c){
	return c == 'a' ? 0 : c == 'e' ? 1 : 2;
}

void jooj(char* j1, char* j2){
	int v1 = valueOf(j1[1]);
	int v2 = valueOf(j2[1]);
	puts(results[matchup[v1][v2]]);
}

int main(void){
	int N;
	char j1[8], j2[8];
	setup();
	scanf("%d", &N);
	while(N--){
		scanf("%s", j1);
		scanf("%s", j2);
		jooj(j1, j2);
	}
	return 0;
}
