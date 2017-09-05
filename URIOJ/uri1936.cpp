/*
 * Leonardo Deliyannis Constantin
 * URI 1936 - Fatorial
 */

#include <stdio.h>
#include <vector>
using namespace std;
const int CEM_MIL = (int(1e5));
vector<int> fat;

void geraFat(){
	fat.push_back(1);
	for(int i = 2; i*fat.back() <= CEM_MIL; i++){
		fat.push_back(i*fat.back());
	}
}

int fatNum(int n){
	int i = (int)fat.size() - 1;
	int cnt = 0, div;
	while(n > 0){
		if(n >= fat[i]){
			div = n / fat[i];
			cnt += div;
			n -= fat[i] * div;
		}
		i--;
	}
	return cnt;
}

int main(){
	int n;
	geraFat();
	while(scanf("%d", &n) != EOF){
		printf("%d\n", fatNum(n));
	}
	return 0;
}
