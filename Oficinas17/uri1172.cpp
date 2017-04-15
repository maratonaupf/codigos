/*
 * Leonardo Deliyannis Constantin
 * URI 1172 - Substituição em Vetor I
 */

#include <iostream>
using namespace std;

int main(){
	int i;
	int X[10];
	for(i = 0; i < 10; i++){
		cin >> X[i];
		if(X[i] <= 0){
			X[i] = 1;
		}
	}
	for(i = 0; i < 10; i++){
		cout << "X[" << i << "] = " << X[i] << endl;
	}
	return 0;
}