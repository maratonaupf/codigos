#include<stdio.h>
#include<iostream>

using namespace std;


int main(void){
	int a, b, c;
	
	while(cin >> a >> b >> c){
		if(a==b || a==c || b==c || a==b+c || b==a+c || c==a+b) cout << 'S';
		else cout << 'N';
		cout << endl;
	}
	return 0;
}
