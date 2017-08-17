#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll vet[10];

main()
{
	int i, N, t;
	ll acum, v[5];
	scanf("%d", &N);
	for(t = 1; t <= N; t++)
	{
		acum = 0;
		for(i = 0; i < 10; i++)
		{
			scanf("%lld", &vet[i]);
			acum += vet[i];
		}
		acum /= 4;
		sort(vet, vet+10);
		v[2] = acum - vet[0] - vet[9];
		v[4] = vet[8] - v[2];
		v[3] = vet[9] - v[4];
		v[0] = vet[1] - v[2];
		v[1] = vet[0] - v[0];
		printf("Case %d: %lld %lld %lld %lld %lld\n", t, v[0], v[1], v[2], v[3], v[4]);
	}
	return 0;
}
