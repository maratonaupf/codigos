/*
 * Anderson A. Fontana
 * Uva 10954 - Add All
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	priority_queue<int, vector<int>, greater<int>> pq;
	int n, aux, sum, a, b;
	while (cin >> n && n != 0)
	{
		while (n--)
		{
			cin >> aux;
			pq.push(aux);
		}

		sum = 0;
		while (pq.size() > 1)
		{
			a = pq.top();
			pq.pop();
			b = pq.top();
			pq.pop();
			sum += a+b;
			pq.push(a+b);
		}

		cout << sum << endl;
		pq.pop();

	}
	return 0;
}