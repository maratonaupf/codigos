/*
 * Leonardo Deliyannis Constantin
 * UVa 10008 - What's Cryptanalysis?
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <algorithm>
using namespace std;
#define MAX 112345

struct freq{
	char letter;
	int count;
};

bool cmp(const freq a, const freq b){
	if(a.count == b.count)
		return a.letter < b.letter;
	return a.count > b.count;
}

int main(){
	int N, tam, i, oc[26];
	char s[MAX];
	freq v[26];
	while(scanf("%d\n", &N) != EOF){
		memset(oc, 0, sizeof(oc));
		while(N--){
			fgets(s, MAX, stdin);
			for(i = 0; s[i] != '\n'; i++){
				if(isalpha(s[i])){
					oc[toupper(s[i]) - 'A']++;
				}
			}
		}
		tam = 0;
		for(i = 0; i < 26; i++){
			if(oc[i] > 0){
				v[tam].letter = 'A' + i;
				v[tam].count = oc[i];
				tam++;
			}
		}
		sort(v, v+tam, cmp);
		for(i = 0; i < tam; i++){
			printf("%c %d\n", v[i].letter, v[i].count);
		}
	}
	return 0;
}
