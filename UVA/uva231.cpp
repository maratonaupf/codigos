/*
 * Leonardo Deliyannis Constantin
 * UVa 231 - Testing the CATCHER
 */

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;

int lds(const vi &v, const int N){
	int i, j, ret;
	vi l(N, 1);
	for(i = 1; i < N; i++)
		for(j = 0; j < i; j++)
			if(v[i] < v[j] && l[i] < l[j] + 1)
				l[i] = l[j] + 1;
	ret = *max_element(l.begin(), l.end());
	return ret;
}

int main(){
	int N = 0, T = 0, aux, last = -1;
	bool first = true;
	vi v;
	while(scanf("%d", &aux), aux != last){
		if(aux != -1){
			v.push_back(aux);
			N++;
		}
		else{
			first ? first = false : printf("\n");
			printf("Test #%d:\n", ++T);
			printf("  maximum possible interceptions: %d\n", lds(v, N));
			v.clear(); 
			N = 0;
		}
		last = aux;
	}
	v.clear();
	return 0;
}
