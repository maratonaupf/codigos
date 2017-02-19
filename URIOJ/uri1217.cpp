#include<iostream>
#include<iomanip>
#include<cctype>

using namespace std;

int main(void){	
	int dias, ct, qt, i;
	string s;
	double acum=0.0, val, kga=0.0,
		kgmed, rsmed;
	cin >> dias;
	for(ct=1; ct<=dias; ct++){
		qt=1;
		cin >> val;
		acum+=val;
		cin.ignore();
		getline(cin, s);
		for(i=0; s[i]; i++) 
			if(!isalpha(s[i]))
				qt++; //puts("l2");}
		cout << "day " << ct << ": " << qt << " kg\n";
		kga+=qt;
	}
	kgmed = kga / (double) dias;
	rsmed = acum / (double) dias;
	cout << fixed << setprecision(2) << kgmed << " kg by day\nR$ ";
	cout << fixed << setprecision(2) << rsmed << " by day\n";
	return 0;
}
