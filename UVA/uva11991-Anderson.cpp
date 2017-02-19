/*
 * Anderson A. Fontana
 * Uva 11991 - Easy Problem from Rujia Liu?
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
	int N,M, v, i;
	size_t k;
	map<int, vector<int>> number;
	vector<int> temp;
	while (cin >> N >> M)
	{
		i=1;
		while (N--)
		{
			cin >> v;
			if (number.find(v) == number.end())
				number[v] = temp;
			number[v].push_back(i++);
		}
		while (M--)
		{
			cin >> k >> v;
			if (number.find(v) != number.end() && k <= number[v].size())
				cout << number[v][k-1] << endl;
			else
				cout << "0" << endl;
		}
		number.clear();
	}
	return 0;
}