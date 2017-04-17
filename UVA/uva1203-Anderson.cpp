/*
 * Anderson A. Fontana
 * Uva 1203 - Argus
 */

#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct reg
{
	int Q_num,
		period;
};

class cmp
{
public:
	bool operator() (reg &a, reg &b)
	{
		return ( a.period > b.period || (a.period == b.period && a.Q_num > b.Q_num) );
	}
};

int main()
{
	priority_queue<reg, vector<reg>, cmp> pq;
	map<int, int> registers;
	string s;
	reg aux;
	int k;
	while (cin >> s && s != "#")
	{
		cin >> aux.Q_num >> aux.period;
		registers[aux.Q_num] = aux.period;
		pq.push(aux);
	}
	cin >> k;
	while (k--)
	{
		aux = pq.top();
		pq.pop();
		cout << aux.Q_num << endl;
		aux.period += registers[aux.Q_num];
		pq.push(aux);
	}
	while (!pq.empty())
		pq.pop();
	return 0;
}