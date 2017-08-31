/*
 * Leonardo Deliyannis Constantin
 * UVa 11512 - GATTACA
 */

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 1123

typedef pair<int, int> ii;

char T[MAX], P[MAX];
int n, m;
int RA[MAX], tempRA[MAX];
int SA[MAX], tempSA[MAX];
int c[MAX];
int LCP[MAX];
int Phi[MAX], PLCP[MAX];

void countingSort(int k){
	int i, sum, maxi = max(300, n);
	memset(c, 0, sizeof(c));
	for(i = 0; i < n; i++){
		c[i + k < n ? RA[i + k] : 0]++;
	}
	for(i = sum = 0; i < maxi; i++){
		int t = c[i]; c[i] = sum; sum += t;
	}
	for(i = 0; i < n; i++){
		tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
	}
	for(i = 0; i < n; i++){
		SA[i] = tempSA[i];
	}
}

void constructSA(){
	int i, k, r;
	for(i = 0; i < n; i++){
		RA[i] = T[i];
		SA[i] = i;
	}
	for(k = 1; k < n; k <<= 1){
		countingSort(k);
		countingSort(0);
		tempRA[SA[0]] = r = 0;
		for(i = 1; i < n; i++){
			tempRA[SA[i]] = 
			(RA[SA[i]] == RA[SA[i-1]] &&
			 RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
		}
		for(i = 0; i < n; i++){
			RA[i] = tempRA[i];
		}
		if(RA[SA[n-1]] == n-1) break;
	}
}

void computeLCP(){
	int i, L;
	Phi[SA[0]] = -1;
	for (i = 1; i < n; i++){
		Phi[SA[i]] = SA[i-1];}
	for (i = L = 0; i < n; i++){
		if (Phi[i] == -1) { PLCP[i] = 0; continue; }
		while (T[i + L] == T[Phi[i] + L]) L++;
		PLCP[i] = L;
		L = max(L-1, 0);
	}
	for (i = 0; i < n; i++){
		LCP[i] = PLCP[SA[i]];
	}
}

ii stringMatching(){
	int lo = 0, hi = n-1, mid = lo;
	while(lo < hi){
		mid = lo + (hi-lo)/2; // avoid overflows
		int res = strncmp(T+SA[mid], P, m);
		if(res >= 0) hi = mid;
		else lo = mid + 1;
	}
	if(strncmp(T+SA[lo], P, m) != 0) return ii(-1, -1);
	ii ans; ans.first = lo;
	lo = 0; hi = n-1; mid = lo;
	while(lo < hi){
		mid = lo + (hi-lo)/2; // avoid overflows
		int res = strncmp(T+SA[mid], P, m);
		if(res > 0) hi = mid;
		else lo = mid + 1;
	}
	if(strncmp(T+SA[hi], P, m) != 0) hi--;
	ans.second = hi;
	return ans;
}

ii LRS(){
	int i, idx = 0, maxLCP = -1;
	for(i = 1; i < n; i++)
		if(LCP[i] > maxLCP)
			maxLCP = LCP[i], idx = i;
	return ii(maxLCP, idx);
}

int main(){
	int tc;
	ii pos;
	scanf("%d\n", &tc);
	while(tc--){
		n = (int)strlen(fgets(T, MAX, stdin));
		T[n-1] = '$';
		constructSA();
		computeLCP();
		ii ans = LRS();
		if(ans.first <= 0)
			printf("No repetitions found!\n");
		else{
			strncpy(P, T+SA[ans.second], m = ans.first);
			P[m] = 0;
			pos = stringMatching();
			pos.second++;
			printf("%s %d\n", P, pos.second - pos.first);
		}
	}
	return 0;
}
