/*
 * Leonardo Deliyannis Constantin
 * Header
 */

#include <iostream>
#define MAX 1123
using namespace std;

int main(){
	int N, X[MAX], i;
	int pos = 0;
	cin >> N;
	for(i = 0; i < N; i++){
		cin >> X[i];
		if(X[i] < X[pos]){
			pos = i;
		}
	}
	cout << "Menor valor: " << X[pos] << endl;
	cout << "Posicao: " << pos << endl;
	return 0;
}
