/*
 * Anderson A. Fontana
 * UVa 11385 - Da Vinci Code
 */

#include <iostream>
#include <map>

#define MAX 2147483648 // 2^31
#define CIPHER 100

using namespace std;

void calculaFibonacci(map<unsigned int, int> &fib)
{
	unsigned int i{0}, a{0}, b{1}, temp;
	while (b < MAX)
	{
		fib[b] = i++;
		temp = a + b;
		a = b;
		b = temp;
		// cout << b << endl;
	}
}

int main()
{
	unsigned int i, N, T, temp, maior, index[CIPHER];
	char str[CIPHER];
	string s, inpt;

	map<unsigned int, int> fib;

	calculaFibonacci(fib);

	cin >> T;
	while (T--)
	{
		cin >> N;

		// Lê a lista de numeros, já trocando para indices
		maior = 0;
		for (i = 0; i < N; ++i)
		{
			cin >> temp;
			index[i] = fib[temp];
			if (index[i] > maior)
				maior = index[i];
		}

		// Lê a string
		cin.ignore();
		getline(cin, s);
		inpt="";
		for (char c : s)
			if (isupper(c))
				inpt.push_back(c);

		// Adiciona espaços
		for (i = 0; i < maior; ++i)
			str[i] = ' ';
		
		// Transfere com base no indice
		for (i = 0; i < N; ++i)
			str[index[i]-1] = inpt[i];

		// Mostra
		for (i = 0; i < maior; ++i)
			cout << str[i];
		cout << endl;
	}

	return 0;
}