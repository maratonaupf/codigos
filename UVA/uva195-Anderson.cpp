/*
 * Anderson A. Fontana
 * Uva 195 - Anagram
 */

#include <iostream>
#include <algorithm>    // next_permutation, sort

using namespace std;

bool cmp (char a, char b)
{
	if ((islower(a) && islower(b)) || (isupper(a) && isupper(b))) 
		return a < b;
	else if (isupper(a))
		return tolower(a) <= b;
	else
		return a < tolower(b);
}

int main()
{
	int n;
	cin >> n;
	string word;
	while(n--)
	{
		cin >> word;
		sort(word.begin(), word.end(), cmp);
		do {
			cout << word << endl;
		} while(next_permutation(word.begin(), word.end(), cmp));
	}
	return 0;
}