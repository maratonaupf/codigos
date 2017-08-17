#include<bits/stdc++.h>
#define INFN (int)-1e9

using namespace std;

set<int> conju;
set<int>::iterator it;
vector<int> vet;

int memo[4001], n, a, b, c;

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int solve(int x)
{
	int i, ans = INFN;
	if(x < 0)
		return INFN;
	if(x == 0)
		return 0;
	if(memo[x] != -1)
		return memo[x];
	for(i = 0; i < vet.size(); i++)
	{
		ans = max(ans, solve(x-vet[i])+1);
	}
	return memo[x] = ans;
}

main()
{
	int i;
	scanf("%d %d %d %d", &n, &a, &b, &c);
	for(i = 0; i <= n; i++)
		memo[i] = -1;
	conju.insert(a);
	conju.insert(b);
	conju.insert(c);
	for(it = conju.begin(); it != conju.end(); it++)
		vet.push_back(*it);
	printf("%d\n", solve(n));
	return 0;
}
