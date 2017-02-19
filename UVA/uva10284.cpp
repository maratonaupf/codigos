#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 8
//#define DEBP

char grid[MAX][MAX+1];

void setBoard(char s[]){
	int k, i, j;
	i = j = 0;
	memset(grid, '.', sizeof(grid));
	for(k = 0; s[k] != '\n'; k++){
		if(s[k] == '/'){
			i++;
			j = 0;
		}
		if(isdigit(s[k])){
			j+= s[k] - '0';
		}
		if(isalpha(s[k])){
			grid[i][j++] = s[k];
		}
	}
}

#ifdef DEBP
void printBoard(){
	int i;
	for(i = 0; i < MAX; i++){
		grid[i][MAX] = '\0';
		puts(grid[i]);
	}
	puts("");
}
#endif

bool isValid(int i2, int j2){
	return (0 <= i2 && i2 < MAX && 0 <= j2 && j2 < MAX);
}

void check(int i2, int j2){
	if(isValid(i2, j2) && grid[i2][j2] == '.') grid[i2][j2] = '*';
}

void blackPawn(int i, int j){
	int k;
	int di[] = { 1, 1};
	int dj[] = {-1, 1};
	for(k = 0; k < 2; k++){
		check(i+di[k], j+dj[k]);
	}
}

void whitePawn(int i, int j){
	int k;
	int di[] = { -1, -1};
	int dj[] = { -1,  1};
	for(k = 0; k < 2; k++){
		check(i+di[k], j+dj[k]);
	}
}

void knight(int i, int j){
	int k;
	int di[] = { -2, -2, -1, -1,  1,  1,  2, 2};
	int dj[] = { -1,  1, -2,  2, -2,  2, -1, 1};
	for(k = 0; k < 8; k++){
		check(i+di[k], j+dj[k]);
	}
}

void king(int i, int j){
	int k;
	int di[] = { -1, -1, -1,  0, 0,  1, 1, 1};
	int dj[] = { -1,  0,  1, -1, 1, -1, 0, 1};
	for(k = 0; k < 8; k++){
		check(i+di[k], j+dj[k]);
	}
}

/* NECESSITAVA DE MODIFICAÇÃO */
void rook(int i, int j){
	int di[] = { -1,  0, 0, 1};
	int dj[] = {  0, -1, 1, 0};
	bool ok[] = { 1,  1, 1, 1};
	int k, w, i2, j2;
	for(k = 1; k < 8; k++){
		for(w = 0; w < 4; w++) if(ok[w]){
			i2 = i+di[w]*k;
			j2 = j+dj[w]*k;
			check(i2, j2);
			if(grid[i2][j2] != '*') ok[w] = false;
		}
	}
}

void bishop(int i, int j){
	int di[] = { -1, -1,  1, 1};
	int dj[] = { -1,  1, -1, 1};
	bool ok[] = { 1,  1,  1, 1};
	int k, w, i2, j2;
	for(k = 1; k < 8; k++){
		for(w = 0; w < 4; w++) if(ok[w]){
			i2 = i+di[w]*k;
			j2 = j+dj[w]*k;
			check(i2, j2);
			if(grid[i2][j2] != '*') ok[w] = false;
		}
	}
}

void queen(int i, int j){
	int di[] = { -1, -1, -1,  0, 0,  1, 1, 1};
	int dj[] = { -1,  0,  1, -1, 1, -1, 0, 1};
	bool ok[] = { 1,  1,  1,  1, 1,  1, 1, 1};
	int k, w, i2, j2;
	for(k = 1; k < 8; k++){
		for(w = 0; w < 8; w++) if(ok[w]){
			i2 = i+di[w]*k;
			j2 = j+dj[w]*k;
			check(i2, j2);
			if(grid[i2][j2] != '*') ok[w] = false;
		}
	}
}
/* FIM DAS MODIFICAÇÕES */

void markTerritory(int i, int j){
	switch(toupper(grid[i][j])){
		case 'P':
			if(grid[i][j] == 'p') blackPawn(i, j);
			else whitePawn(i, j); 
			break;
		case 'R':
			rook(i, j);
			break;
		case 'N':
			knight(i, j);
			break;
		case 'B':
			bishop(i, j);
			break;
		case 'Q':
			queen(i, j);
			break;
		case 'K':
			king(i, j);
			break;
	}
}

int main(void){
	int i, j, safeSpaces;
	char s[82];
	while(fgets(s, 82, stdin) != NULL){
		setBoard(s);
		for(i = 0; i < 8; i++){
			for(j = 0; j < 8; j++){
				markTerritory(i, j);
			}
		}
		safeSpaces = 0;
		for(i = 0; i < 8; i++){
			for(j = 0; j < 8; j++){
				if(grid[i][j] == '.') safeSpaces++;
			}
		}
		printf("%d\n", safeSpaces);
	}
	return 0;
}
