#include<stdio.h>
#include<set>
using namespace std;

int main(void){
	int N, M, disc, count;
	set<int> jack;
	while(scanf("%d %d", &N, &M), N != 0 || M != 0){
		count = 0; 
		while(N--){
			scanf("%d", &disc);
			jack.insert(disc);
		}
		while(M--){
			scanf("%d", &disc);
			if(jack.count(disc)) count++;
		}
		printf("%d\n", count);
		jack.clear();
	}
	return 0;
}
