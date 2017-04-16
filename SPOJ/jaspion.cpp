/*
 * Leonardo Deliyannis Constantin
 * http://br.spoj.com/problems/JASPION/
 */

#include <stdio.h>
#include <string.h>
#include <string>
#include <map>
#define LEN 82
using namespace std;

int main(){
	int T, M, N;
	scanf("%d\n", &T);
	char jp[LEN], pt[LEN];
	char *tok;
	while(T--){
		scanf("%d %d\n", &M, &N);
		map<string, string> m;
		while(M--){
			fgets(jp, LEN, stdin);
			fgets(pt, LEN, stdin);
			// remove newline from strings
			jp[strlen(jp) - 1] = '\0';
			pt[strlen(pt) - 1] = '\0';
			m[jp] = pt;
		}
		while(N--){
			bool first = true;
			fgets(jp, LEN, stdin);
			tok = strtok(jp, " \n");
			while(tok != NULL){
				first ? first = false : printf(" ");
				printf("%s", m.count(tok) ? m[tok].c_str() : tok);
				tok = strtok(NULL, " \n");
			}
			printf("\n");
		}
	}
	return 0;
}
