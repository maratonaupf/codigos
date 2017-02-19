#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;

bool p2(int n){
	do{
		if(n == 2) return true;
		if(n & 1) return false;
		n /= 2;	
	}while(n);
	return false;
} 

int main(void){
	int N, i, m,
		p[3], v[3];
	string s[4] = {"Uilton", "Rita", "Ingred", "URI"};
	
	while(scanf("%d", &N), N){
		p[0] = p[1] = p[2] = 0;
		
		while(N--){
			m = 0;
			for(i=0; i<3; i++){
				scanf("%d", v+i);
				
				if( p2(v[i]) ){
					p[i]++;
				}
				if( v[i] > v[m]){ m = i; }
			}
			if( p2(v[m])) p[m]++;
		}
		m = 0;
		for(i=	1; i<3; i++)
			if(p[i] > p[m]){
				m = i;
			}
		sort(p, p+3);
		if(p[1] == p[2]) m = 3;
		printf("%s\n", s[m].c_str());
	}
	return 0;
}

