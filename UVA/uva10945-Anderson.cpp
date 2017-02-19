/*
 * Anderson A. Fontana
 * Uva 10945 - Mother Bear
 */

#include <iostream>

using namespace std;

int main()
{
	int tam, i;
	string inpt, clean;
	bool palindromo;
	while (getline(cin, inpt) && inpt != "DONE")
	{
		clean="";
		for (char c : inpt)
			if (isalpha(c))
				clean += tolower(c);
		palindromo = true;
		tam = clean.length();
		for (i = 0; i <= tam/2; ++i)
			if (clean[i] != clean[tam-i-1])
			{
				palindromo = false;
				break;
			}
		if(palindromo)
			cout << "You won't be eaten!" << endl;
		else
			cout << "Uh oh.." << endl;
	}
	return 0;
}