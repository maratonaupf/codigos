#include<stdio.h>
#include<list>
#define MAX 112345

using namespace std;

int main(void){
	list<char> ls;
	list<char>::iterator it;
	char s[MAX];
	while(scanf("%s", s) != EOF){
		it = ls.begin();
		for(int i = 0; s[i] != '\0'; i++){
			if('['){
				it = ls.begin();
				//it--;
			}else if(']'){
				it = ls.end();
			}else{
				ls.insert(it, s[i]);
			}
		}
		for(it = ls.begin(); it != ls.end(); ++it){
			putchar(*it);
		}
		putchar('\n');
		ls.clear();
	}
	return 0;
}
