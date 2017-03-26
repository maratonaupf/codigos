/*
 * Leonardo Deliyannis Constantin
 * Header
 */

#include <iostream>

using namespace std;

int main(){
	for(int cont = 5; cont > 0; cont--){
		cout << "Autodestruicao em " << cont << "..." << endl;
		system("sleep 1");
	}

	cout << "BOOM!" << endl;
	return 0;
}