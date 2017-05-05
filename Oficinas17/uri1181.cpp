/*
 * Leonardo Deliyannis Constantin
 * URI 1181 - Linha na Matriz
 */

#include <iostream>
#include <iomanip>
using namespace std;
#define MAX 12

int main(){
	double mat[MAX][MAX], soma;
	int L;
	int i, j;
	char T;

	cin >> L;
	cin >> T;
	for(i = 0; i < MAX; i++){
		for(j = 0; j < MAX; j++){
			cin >> mat[i][j];
		}
	}
	soma = 0;
	for(j = 0; j < MAX; j++){
		//soma = soma + mat[L][j];
		soma += mat[L][j];
	}
	cout << fixed << setprecision(1);
	// ( (Condição) ? [Verdadeiro] : [Falso] )
	cout << ((T == 'M') ? soma / (double) MAX : soma) << endl;
	return 0;
}
