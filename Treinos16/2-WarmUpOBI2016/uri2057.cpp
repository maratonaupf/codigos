#include<stdio.h>
//#include<iostream>
//using namespace std;

int main(void){
	int S, T, F; // Supremo Tribunal Federal? :v 
	//while(cin >> S >> T >> F){
	while(scanf("%d %d %d", &S, &T, &F) != EOF){
		int resp = (S+T+F) % 24;
		if(resp < 0) resp+=24;
		//cout << resp << endl;
		printf("%d\n", resp);
	}
	return 0;
}
