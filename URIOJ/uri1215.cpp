#include<stdio.h>
#include<ctype.h>
#include<set>
#include<string>
#define MAX 212

using namespace std;

int main(void){
	char s[MAX];
	int c, tam = 0;
	set<string> st;
	while((c = getchar()) != EOF){
		if(isalpha(c)){
			s[tam++] = tolower(c);
		}else if(tam){
			s[tam] = '\0';
			tam = 0;
			st.insert((string) s);
		}
	}
	set<string>::iterator it;
	for(it = st.begin(); it != st.end(); ++it){
		printf("%s\n", (*it).c_str());
	}
	st.clear();
	return 0;
}
