#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int main(void){
	vector<int> v;
	int N = 0, x, median;
	while(scanf("%d", &x) != EOF){
		N++;
		v.insert(upper_bound(v.begin(), v.end(), x), x);
		median = (N&1) ? v[N/2] : 
			v[N/2 - 1] + (v[N/2] - v[N/2 - 1]) / 2;
		printf("%d\n", median);
	}
	v.clear();
	return 0;
}
