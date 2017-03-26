/*
 * Leonardo Deliyannis Constantin
 * URI 1064 - Positivos e Média
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int i, pos;
	double val, media, acum;
	acum = 0.0;
	pos = 0;
	for(i = 0; i < 6; i++){
		cin >> val;
		if(val >= 0.0){
			acum += val;
			pos++;
		}
	}
	media = acum / (double)pos;
	cout << pos << " valores positivos" << endl;
	cout << fixed << setprecision(1) << media;
	return 0;
}