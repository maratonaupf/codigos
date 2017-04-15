/*
 * Leonardo Deliyannis Constantin
 * 
 */

#include <iostream>
using namespace std;

int main(){
	int i, cont;
	string nomes[10];
	cont = 0;
	for(i = 0; i < 10; i++){
		cin >> nomes[i];
		if(nomes[i][0] == 'A' || 
			nomes[i][0] == 'E' || 
			nomes[i][0] == 'I' ||
			nomes[i][0] == 'O' || 
			nomes[i][0] == 'U'){
			cont++;
		}
	}
	for(i = 0; i < 10; i++){
		cout << nomes[i] << endl;
	}
	cout << cont << " nome(s) comecam com vogais" << endl;
	return 0;
}