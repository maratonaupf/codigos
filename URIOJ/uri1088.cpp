/*
 * Leonardo Deliyannis Constantin
 * URI 1088 - Bolhas e Baldes
 */

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 112345

typedef unsigned long long ull;
typedef vector<int> vi;

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
	int v[MAX];
	int N, i;
	while(scanf("%d", &N), N != 0){
		for(i = 0; i < N; i++){
			scanf("%d", v+i);
		}
		printf("%s\n", mergesort(v, N) & 1ULL? "Marcelo" : "Carlos");
	}
	return 0;
}
