/*
 * Leonardo Deliyannis Constantin
 * Heap binária
 */

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;
#define PAI(x) (((x)-1)>>1)
#define ESQ(x) (((x)<<1)+1)
#define DIR(x) (((x)<<1)+2)

int calls;
int _heapSize;

void maxHeapify(vector<int> &V, int i){
	int l = ESQ(i);
	int r = DIR(i);
	
	int largest;
	if(l < _heapSize && V[l] > V[i]){
		largest = l;
	}
	else{
		largest = i;
	}
	if(r < _heapSize && V[r] > V[largest]){
		largest = r;
	}
	if(largest != i){
		swap(V[i], V[largest]);
		maxHeapify(V, largest);
	}
}

void buildMaxHeap(vector<int> &V){
	calls = 0;
	_heapSize = V.size();
	for(int i = _heapSize/2 + 1; i >= 0; i--){
		maxHeapify(V, i);
	}
}

void heapsort(vector<int> &V){
	buildMaxHeap(V);
	for(int i = V.size()-1; i >= 1; i--){
		swap(V[0], V[i]);
		_heapSize--;
		maxHeapify(V, 0);
	}
}

bool isSorted(const vector<int> &v){
	for(auto it = v.begin()+1; it != v.end(); ++it){
		if(*(it-1) > *it) return false;
	}
	return true;
}

int main(){
	int N;
	while(scanf("%d", &N) != EOF && N != 0){
		vector<int> v(N, 0);
		for(int i = 0; i < N; i++){
			scanf("%d", &v[i]);
		}
		heapsort(v);
		assert(isSorted(v));
		vector<int>::iterator it;
		for(it = v.begin(); it != v.end(); ++it){
			printf("%d%c", *it, it != v.end()-1 ? ' ' : '\n');
		}
	}
	return 0;
}
