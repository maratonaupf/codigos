#include<iostream>
#include<iomanip>
#define PI 3.14159
using namespace std;

int main(){
	double raio, area;
	cin >> raio;
	area = PI * raio * raio;
	cout << "A=" << fixed << setprecision(4) << area << endl;
	return 0;
}
