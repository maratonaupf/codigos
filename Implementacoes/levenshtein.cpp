/*
 * Leonardo Deliyannis Constantin
 * levenshtein - compares two strings and shows edit distance between them
 */

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 112

int memo[MAX][MAX];

void printMemo(const char *n, const char *m, const int a, const int b){
	for(int i = -1; i <= a; i++){
		for(int j = -1; j <= b; j++){
			if (i == -1) printf("%3c%c", j <= 0 ? ' ' : m[j-1], j < b ? ' ' : '\n');
			else if (j < 0) printf("%3c ", i <= 0 ? ' ' : n[i-1]);
			else printf("%3d%c", memo[i][j], j < b ? ' ' : '\n');
		}
	}
}

inline int min3(int a, int b, int c){ return min(a, min(b, c)); }

int editDist(const char *n, const char *m, const int a, const int b){
	if(memo[a][b] != -1) return memo[a][b];
	if(b == 0) return memo[a][b] = a;
	if(a == 0) return memo[a][b] = b;
	return memo[a][b] = min3(
		editDist(n, m, a, b-1) + 1,
		editDist(n, m, a-1, b) + 1,
		editDist(n, m, a-1, b-1) + ((n[a-1] == m[b-1]) ? 0 : 1)
	);
}

int main(){
	char s1[MAX], s2[MAX];
	size_t t1, t2;
	while(fgets(s1, MAX, stdin) && s1[0] != '#' && fgets(s2, MAX, stdin) && s2[0] != '#'){
		s1[t1 = strlen(s1) - 1] = s2[t2 = strlen(s2) - 1] = 0;
		memset(memo, -1, sizeof(memo));
		printf("Edit distance between strings \"%s\" and \"%s\" is: %d\n", s1, s2,
			editDist(s1, s2, t1, t2));
		printMemo(s1, s2, t1, t2);
	}
	return 0;
}

