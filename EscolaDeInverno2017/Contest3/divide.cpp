#include<stdio.h>

int memo[10001][501];
long long acum[501];
int N, M;

long long min(long long a, long long b)
{
	return (a < b) ? a : b;
}

main()
{
	int i, j, x;
	scanf("%d %d", &N, &M);
	for(i = 1; i <= M; i++)
	{
		scanf("%d", &x);
		acum[i] = acum[i-1] + x;
	}
	for(i = 1; i <= N; i++)
	{
		for(j = 1; j <= M; j++)
		{
		
		}
	}
	printf("%lld\n", solve(N, 0));
	return 0;
}
