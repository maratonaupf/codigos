/*
 * Leonardo Deliyannis Constantin
 * https://open.kattis.com/problems/haypoints
*/

#include <stdio.h>
#include <string.h>
#include <string>
#include <map>
using namespace std;
#define LEN 212

int main(){
	int m, n, d;
	int jobVal;
	char s[LEN];
	while(scanf("%d %d ", &m, &n) != EOF){
		map<string, int> val;
		while(m--){
			scanf("%s %d", s, &d);
			val[s] = d;
		}
		while(n--){
			jobVal = 0;
			while(scanf("%s", s), strcmp(s, ".") != 0){
				jobVal += val[s];
			}
			printf("%d\n", jobVal);
		}
	}
	return 0;
}
