#include<stdio.h>
//#include<iostream>

//using namespace std;

int main(void){
	int N;
	char s[24];
	//while(cin >> N){
	while(scanf("%d", &N) != EOF){
		while(N--){
			//cin >> s;
			scanf("%s", s);
			if((s[3] == '\0') && ((s[0] == 'O' && s[1] == 'B') ||
				(s[0] == 'U' && s[1] == 'R'))){
				s[2] = 'I';
			}
			/*
			cout << s;
			if(N > 0){
				cout << " ";
			}
			else{
				cout << endl;
			}
			*/	
			printf("%s%c", s, N ? ' ' : '\n');
		}
	}
	return 0;
}
