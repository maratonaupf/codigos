/*
 * Anderson A. Fontana
 * Uva 401 - Palindromes
 */

#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<char, char> m;
	m['A'] = 'A';
	m['E'] = '3';
	m['H'] = 'H';
	m['I'] = 'I';
	m['J'] = 'L';
	m['L'] = 'J';
	m['M'] = 'M';
	m['O'] = 'O';
	m['S'] = '2';
	m['T'] = 'T';
	m['U'] = 'U';
	m['V'] = 'V';
	m['W'] = 'W';
	m['X'] = 'X';
	m['Y'] = 'Y';
	m['Z'] = '5';
	m['1'] = '1';
	m['2'] = 'S';
	m['3'] = 'E';
	m['5'] = 'Z';
	m['8'] = '8';

	int tam, i;
	bool palindromo, espelhado;
	string palavra;
	while (cin >> palavra)
	{
		tam = palavra.length();
		palindromo = espelhado = true;
		for (i = 0; i <= tam/2; ++i)
		{
			if (palindromo && palavra[i] != palavra[tam-i-1])
				palindromo = false;
			if (espelhado && (m.find(palavra[i]) == m.end() || m[palavra[i]] != palavra[tam-i-1]))
				espelhado = false;
		}
		cout << palavra;
		if		( palindromo &&  espelhado)	cout << " -- is a mirrored palindrome.";
		else if	( palindromo && !espelhado)	cout << " -- is a regular palindrome.";
		else if	(!palindromo &&  espelhado)	cout << " -- is a mirrored string.";
		else								cout << " -- is not a palindrome.";
		cout << endl << endl;
	}
	return 0;
}