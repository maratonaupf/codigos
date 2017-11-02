/*
 * Leonardo Deliyannis Constantin
 * UVa 102 - Ecological Bin Packing
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef vector<int> vi;

int main(){
	int v[9], i, ans;
	int curr, total;
	string mask, mymask;
	while(scanf("%d", &v[0]) != EOF){
		total = v[0];
		for(i = 1; i < 9; i++){
			scanf("%d", &v[i]);
			total += v[i];
		}
		map<char, vi> m;
		for(char c : "BGC"){
			m[c].assign(3, 0);
		}
		for(i = 0; i < 3; i++){
			m['B'][i] += v[i*3 + 0];
			m['G'][i] += v[i*3 + 1];
			m['C'][i] += v[i*3 + 2];
 		}
 		mask = "BCG";
 		ans = -1;
 		do{
 			curr = total;
 			for(i = 0; i < 3; i++){
 				curr -= m[mask[i]][i];
 			}
 			if(ans == 	-1 || ans > curr){
 				ans = curr;
 				mymask = mask;
 			}
 		}while(next_permutation(mask.begin(), mask.end()));
		printf("%s %d\n", mymask.c_str(), ans);
	}
	return 0;
}
