/*
 * Anderson A. Fontana
 * Uva 11503 - Virtual Friends
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct node
{
	int id,
		sz;
};

vector<node> info;

int FIND(int x)
{
	if (info[x].id == x) return x;
	info[x].id = FIND(info[x].id);
	return info[x].id;
}
int UNION(int a, int b)
{
	a = FIND(a);
	b = FIND(b);
	if (a == b)
		return info[a].sz;
	if (info[a].sz > info[b].sz)
		swap(a,b);
	info[a].id = b;
	info[b].sz += info[a].sz;
	return info[b].sz;
}

void add(map<string, int> &ids, string x)
{
	if (ids.find(x) == ids.end())
	{
		int id = info.size();
		ids[x] = id;
		info.push_back({id, 1});
	}
}

int main()
{
	map<string, int> ids;
	int N, F;
	string a, b;
	cin >> N;
	while (N--)
	{
		cin >> F;
		while (F--)
		{
			cin >> a >> b;
			add(ids, a);
			add(ids, b);
			cout << UNION(ids[a], ids[b]) << endl;
		}
		ids.clear();
		info.clear();
	}
	return 0;
}