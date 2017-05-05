/*
 * Leonardo Deliyannis Constantin
 * https://www.urionlinejudge.com.br/judge/pt/problems/view/1960
 */

#include<iostream>
using namespace std;

int main(void){
	int n;
	while(cin >> n){
		switch(n / 100){
			case 1: cout << "C"; break;
			case 2: cout << "CC"; break;
			case 3: cout << "CCC"; break;
			case 4: cout << "CD"; break;
			case 5: cout << "D"; break;
			case 6: cout << "DC"; break;
			case 7: cout << "DCC"; break;
			case 8: cout << "DCCC"; break;
			case 9: cout << "CM"; break;
		}
		n %= 100;
		switch(n / 10){
			case 1: cout << "X"; break;
			case 2: cout << "XX"; break;
			case 3: cout << "XXX"; break;
			case 4: cout << "XL"; break;
			case 5: cout << "L"; break;
			case 6: cout << "LX"; break;
			case 7: cout << "LXX"; break;
			case 8: cout << "LXXX"; break;
			case 9: cout << "XC"; break;
		}
		n %= 10;
		switch(n){
			case 1: cout << "I"; break;
			case 2: cout << "II"; break;
			case 3: cout << "III"; break;
			case 4: cout << "IV"; break;
			case 5: cout << "V"; break;
			case 6: cout << "VI"; break;
			case 7: cout << "VII"; break;
			case 8: cout << "VIII"; break;
			case 9: cout << "IX"; break;
		}
		cout << endl;
	}
	return 0;
}
