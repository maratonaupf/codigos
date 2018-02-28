/*
 * Leonardo Deliyannis Constantin
 * CodeForces 5C - Longest Regular Bracket Sequence
*/

#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;
#define MAX 1123456

typedef pair<int, int> ii;
bool v[MAX];
int freq[MAX];

ii solve(const char *s){
	int i, ans, curr, cnt;
	bool streak;
	stack<int> p;
	memset(v, 0, sizeof(v));
	memset(freq, 0, sizeof(freq));
	for(i = 0; s[i] != '\n'; i++){
		if(s[i] == '('){
			p.push(i);
		}
		if(s[i] == ')'){
			if(!p.empty()){
				v[p.top()] = v[i] = 1;
				p.pop();
			}
		}
	}
	ans = curr = cnt = 0;
	streak = false;
	for(i = 0; s[i] != '\0'; i++){
		if(v[i] == 1 && (i == 0 || v[i-1] == 0)){
			cnt++;
			streak = true;
		}
		if(v[i] == 0){
			streak = false;
			ans = max(ans, curr);
			freq[curr]++;
			curr = 0;
		}
		if(streak) curr++;
	}
	if(cnt == 0) return {0, 1};
	return {ans, freq[ans]};
}

int main(){
	char s[MAX];
	while(fgets(s, MAX, stdin) != NULL){
		ii ans = solve(s);
		printf("%d %d\n", ans.first, ans.second);
	}
	return 0;
}
