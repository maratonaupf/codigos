/*
 * Leonardo Deliyannis Constantin
 * Header
 */

#include <iostream>
using namespace std;

int main(){
	int par[5], impar[5];
	int tp = 0, ti = 0;
	int i, j, val;
	for(i = 0; i < 15; i++){
		cin >> val;
		if((val % 2) == 0){
			par[tp] = val;
			tp++;
			if(tp == 5){
				for(j = 0; j < 5; j++){
					cout << "par[" << j << "] = " << par[j] << endl;
				}
				tp = 0;
			}
		}
		else{
			impar[ti] = val;
			ti++;
			if(ti == 5){
				for(j = 0; j < 5; j++){
					cout << "impar[" << j << "] = " << impar[j] << endl;
				}
				ti = 0;
			}
		}
	}
	for(i = 0; i < ti; i++){
		cout << "impar[" << i << "] = " << impar[i] << endl;
	}
	for(i = 0; i < tp; i++){
		cout << "par[" << i << "] = " << par[i] << endl;
	}
	return 0;
}
