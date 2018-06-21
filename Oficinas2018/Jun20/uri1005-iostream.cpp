#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	double a, b;
	double media;
	while(cin >> a >> b){
		media = (a * 3.5 + b * 7.5) / 11.0;
		cout << "MEDIA = " << fixed << setprecision(5) << media << endl;
	}
	return 0;
}
