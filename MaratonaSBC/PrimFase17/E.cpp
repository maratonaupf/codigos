#include<stdio.h>
#include<bitset>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 12

bool menor[12]=  {0   ,1    ,0   ,1    ,0   ,0   ,1    ,0    ,1     ,0   ,1    ,0};
string notas[12]={"do","do#","re","re#","mi","fa","fa#","sol","sol#","la","la#","si"};

bitset<MAX> bs;

int main(){
	int n, i, j, aux, pos, ans;
	bool aqui;
	while(scanf("%d", &n) != EOF){
		bs.reset();
		for(int i = 0; i < n; i++) {
			scanf("%d", &aux);
			bs[(aux-1)%12] = 1;
		}
		ans = -1;
		//cerr << bs << endl;
		for(i = 0; i < 12; i++){
			aqui = true;
			for(j = 0; j < 12; j++){
				pos = (i+j)%12;
				if(bs[pos] && menor[j]){
					//fprintf(stderr, "i: %d, j: %d, errou\n", i, j);
					aqui = false; break;
				}
			}
			if(aqui){ ans = i; break; }
		}
		printf("%s\n", (ans != -1) ? notas[ans].c_str() : "desafinado");
	}
	
	return 0;
}
