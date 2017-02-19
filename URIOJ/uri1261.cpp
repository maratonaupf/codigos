#include<stdio.h>
#include<map>
#include<string>
#include<string.h>

using namespace std;

int main(void){
	int M, N, i, value;
	char s[20];
	map<string, int> mymap;
	string str;
	scanf("%d %d", &M, &N);
	for(i = 0; i < M; i++){
		scanf("%s %d", s, &value);
		mymap[str = s] = value;
	}
	for(i = 0; i < N; i++){
		value = 0;
		while(scanf("%s", s), strcmp(s,".")){
			if(mymap.find(str = s) != mymap.end())
				value += mymap[str];
		}
		printf("%d\n", value);
	}
	
	return 0;
}
