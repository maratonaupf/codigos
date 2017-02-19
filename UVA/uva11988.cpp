#include<stdio.h>
#include<list>
using namespace std;

int main(void){
	int c;
	list<char> l;
	list<char>::iterator it;
	it = l.begin();
	while((c = getchar()) != EOF){
		if(c == '\n'){
			for(it = l.begin(); it != l.end(); ++it){
				putchar(*it);
			}
			putchar('\n');
			l.clear();
			it = l.begin();
		}
		else if(c == '[') it = l.begin();
		else if(c == ']') it = l.end();
		else l.insert(it, c);
	}
	return 0;
}
