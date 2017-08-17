#include<bits/stdc++.h>
#define ll long long

using namespace std;

int N;
vector<ll> A;

main()
{
	int i, c, j, T, x;
	ll sum;
	scanf("%d", &T);
	while(T--)
	{
		sum = 0;
		A.clear();
		scanf("%d", &N);
		for(i = 0; i < N; i++)
		{
			scanf("%d", &x);
			A.push_back(x);
		}
		for(i = 0; i < N; i++)
		{
			scanf("%d", &x);
			A[i] -= x;
		}
		sort(A.begin(), A.end());
		for(i = 0; i < N; i++)
			if(A[i] >= 0)
				break;
		c = N-i;
		for(j = i; j < N; j++)
			sum += A[j];
		for(j = i-1; j >= 0; j--)
		{
			if(sum + A[j] < 0)
				break;
			sum += A[j];
			c++;
		}
		printf("%d\n", c);
	}
	return 0;
}
