/*
 * Anderson A. Fontana
 * Uva 624 - CD
 */

#include <iostream>
#include <vector>

using namespace std;
vector<int> tracks, final;
int sum, nearSum, inSum, N;

bool backTracks(int i)
{
	if (sum == inSum)
		return true;
	if (nearSum < sum)
		nearSum = sum;
	if (i == N)
		return false;
	while(i < N)
	{
		if (sum + tracks[i] <= inSum)
		{
			sum += tracks[i];
			final.push_back(tracks[i]);
			if (backTracks(i+1))
				return true;
			sum -= tracks[i];
			final.pop_back();
		}
		i++;
	}
	return false;
}

int main()
{
	int track;
	while (cin >> inSum >> N)
	{
		for (int i = 0; i < N; ++i)
		{
			cin >> track;
			tracks.push_back(track);
		}
		sum = 0;
		nearSum = 0;
		while (!backTracks(0))
		{
			inSum = nearSum;
			final.clear();
		}
		for (size_t i = 0; i < final.size(); ++i)
			cout << final[i] << " ";
		cout << "sum:" << sum << endl;
		tracks.clear();
		final.clear();
	}
	return 0;
}