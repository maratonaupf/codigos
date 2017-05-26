/*
 * Leonardo Deliyannis Constantin
 * http://www.spoj.com/problems/INVCNT/
 */

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;
#define MAX 212345
// #define DEBP

typedef unsigned long long ull;
typedef vector<int> vi;

#ifdef DEBP
bool isSorted(int *v, int N){
	int i = 0;
	while(++i < N){
		if(v[i-1] > v[i]) return false;
	}
	return true;
}
#endif

ull merge(int *v, vi &aux, int lo, int mid, int hi){
	int i, j, k;
	ull inv = 0ULL;
	i = lo;
	j = mid;
	k = lo;
	while((i <=  mid - 1) && j <= hi){
		if(v[i] <= v[j]){
			aux[k++] = v[i++];
		}
		else{
			aux[k++] = v[j++];
			inv += mid - i;
		}
	}
	while(i <= mid - 1) aux[k++] = v[i++];
	while(j <= hi) aux[k++] = v[j++];
	copy(aux.begin()+lo, aux.begin()+hi+1, v+lo);
	return inv;
}

ull _mergesort(int *v, vi &aux, int lo, int hi){
	int mid;
	ull inv = 0ULL;
	if(lo < hi){
		mid = lo + (hi-lo) / 2;
		inv += _mergesort(v, aux, lo, mid);
		inv += _mergesort(v, aux, mid+1, hi);
		inv += merge(v, aux, lo, mid+1, hi);
	}
	return inv;
}

ull mergesort(int *v, int N){
	vi aux(N, 0);
	return _mergesort(v, aux, 0, N-1);
}

int main(){
	int T, N, i;
	int v[MAX];
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		for(i = 0; i < N; i++){
			scanf("%d", v+i);
		}
		printf("%llu\n", mergesort(v, N));
		#ifdef DEBP
		assert(isSorted(v, N));
		#endif
	}
	return 0;
}
