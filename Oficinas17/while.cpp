// Clube de Programação UPF 2017 //
//   Laços de Repetição: While   //
#include<iostream>
using namespace std;

int  main(){
	int cnt;
	cin >> cnt;
	while(cnt > 0){
		cout << "Autodestruicao em " << cnt << "..." << endl;
		cnt--; // cnt = cnt - 1;
	}
	cout << "BOOM!" << endl;
	return 0;
}