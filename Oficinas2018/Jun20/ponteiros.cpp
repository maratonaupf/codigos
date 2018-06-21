// typeracer.com é daora :p

#include<iostream>
using namespace std;

int main(){
	double a = 7.5;
	double *p;
	cout << "Valor de A: " << a << endl;
	cout << "Valor de P (lixo): " << p << endl;
	p = &a;
	cout << "Valor de P (&a): " << p << endl;
	cout << "Valor apontado por P: " << *p << endl;
	
	a *= 2;
	cout << "Valor de A: " << a << endl;
	cout << "Valor apontado por P: " << *p << endl;
	
	*p -= 10.5;
	cout << "Valor de A: " << a << endl;
	cout << "Valor apontado por P: " << *p << endl;
	
	cout << "Endereço de P: " << &p << endl;
	return 0;
}
