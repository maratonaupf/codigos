#include<iostream>
//#define DEBUG

using namespace std;

int main(){
	double money;
	int reais, cents;
	int notas, moedas;
	cin >> money;
	reais = (int)money;
	cents = (money - (double)reais) * 100.0;
	
	// só compila se DEBUG estiver definida
	#ifdef DEBUG
	cout << reais << " reais\n";
	cout << cents << " cents\n";
	#endif
	
	cout << "NOTAS:\n";
	notas = reais / 100;
	reais -= notas * 100;
	cout << notas << " nota(s) de R$ 100.00\n";
	
	notas = reais / 50;
	reais -= notas * 50;
	cout << notas << " nota(s) de R$ 50.00\n";
	
	notas = reais / 20;
	reais -= notas * 20;
	cout << notas << " nota(s) de R$ 20.00\n";
	
	notas = reais / 10;
	reais -= notas * 10;
	cout << notas << " nota(s) de R$ 10.00\n";
	
	notas = reais / 5;
	reais -= notas * 5;
	cout << notas << " nota(s) de R$ 5.00\n";
	
	notas = reais / 2;
	reais -= notas * 2;
	cout << notas << " nota(s) de R$ 2.00\n";
	
	cents += reais * 100;
	
	cout << "MOEDAS:\n";
	moedas = cents / 100;
	cents -= moedas * 100;
	cout << moedas << " moeda(s) de R$ 1.00\n";
		
	moedas = cents / 50;
	cents -= moedas * 50;
	cout << moedas << " moeda(s) de R$ 0.50\n";
		
	moedas = cents / 25;
	cents -= moedas * 25;
	cout << moedas << " moeda(s) de R$ 0.25\n";
	
	moedas = cents / 10;
	cents -= moedas * 10;
	cout << moedas << " moeda(s) de R$ 0.10\n";
	
	moedas = cents / 5;
	cents -= moedas * 5;
	cout << moedas << " moeda(s) de R$ 0.05\n";
	
	//moedas = cents;
	//cents -= moedas;
	cout << cents << " moeda(s) de R$ 0.01\n";
	
	return 0;
}
