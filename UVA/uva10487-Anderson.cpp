/*
 * Anderson A. Fontana
 * Uva 10487 - Closest Sums
 */

#include <iostream>
#include <vector>

using namespace std;

int closestSum(vector<int> &set, int num)
{
	int closest{set[1]+set[0]};
	size_t i, j, sz{set.size()};

	for (i = 2; i < sz; ++i)
		for (j = 0; j < i; ++j)
			if ( abs(closest-num) > abs(set[i]+set[j]-num) )
				closest = set[i]+set[j];

	return closest;
}

int main()
{
	int N, M, num, testcase{1};
	vector<int> set;
	while (cin >> N && N!=0)
	{
		while (N-- && cin >> num)
			set.push_back(num);

		cin >> M;
		cout << "Case " << testcase++ << ":" << endl;
		while (M-- && cin >> num)
			cout << "Closest sum to " << num << " is " << closestSum(set, num) << "." << endl;

		set.clear();
	}
	return 0;
}