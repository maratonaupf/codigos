/*
 * Leonardo Deliyannis Constantin
 * https://www.urionlinejudge.com.br/judge/pt/problems/view/1175
 */

#include <iostream>
using namespace std;

int main(){
	int N[20];
	int i, aux;
	for(i = 0; i < 20; i++){
		cin >> N[i];
	}
	for(i = 0; i < 10; i++){
		aux = N[i];
		N[i] = N[19-i];
		N[19-i] = aux;
	}
	for(i = 0; i < 20; i++){
		cout << "N[" << i << "] = " << N[i] << endl;
	}
	return 0;
}
