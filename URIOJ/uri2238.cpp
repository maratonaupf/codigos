/*
 * Leonardo Constantin, Anderson Fontana, 
 * Felipe Batistella e Luis Fontoura
 * URI 2238 - Divisores
*/

#include <stdio.h>
#include <cmath>
#include <set>
using namespace std;

set<int> divisores(int c){
	set<int> ret;
	int lim = sqrt(c);
	for(int i = 1; i <= lim; i++){
		if(c%i == 0){
			ret.insert(i);
			ret.insert(c/i);
		}
	}
	return ret;
}

int main(){
	int a, b, c, d;
	int n, x;
	while(scanf("%d %d %d %d", &a, &b, &c, &d) != EOF){
		set<int> div = divisores(c);
		n = -1;
		for(auto it = div.begin(); it!= div.end(); ++it){
			x = *it;
			if(x%a == 0 && x%b != 0 && d%x != 0){
				n = x;
				break;
			}
		}
		printf("%d\n", n);
	}
	return 0;
}
