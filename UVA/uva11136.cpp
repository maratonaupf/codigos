#include<stdio.h>
#include<set>
using namespace std;

typedef unsigned long long ull;

int main(void){
	int N, K, bill;
	ull count;
	multiset<int> ms;
	while(scanf("%d", &N), N != 0){
		count = 0;
		while(N--){
			scanf("%d", &K);
			while(K--){
				scanf("%d", &bill);
				ms.insert(bill);
			}
			count += *ms.rbegin() - *ms.begin();
			ms.erase(ms.find(*ms.rbegin()));
			ms.erase(ms.begin());
		}
		printf("%llu\n", count);
		ms.clear();
	}
	return 0;
}
