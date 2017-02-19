/* URI 1803 - Matring */

#include<stdio.h>
#include<string.h>
#define MAX 84
#define F (v[0])
#define L (v[N-1])

int main(void){	
	char m[4][MAX], s[MAX];
	int N, i, j, v[MAX];
	while(scanf("%s", m[0]) != EOF){
		N = strlen(m[0]);
		
		for(i = 1; i < 4; i++)
			scanf("%s", m[i]);
		
		memset(v, 0, sizeof(v));
		
		for(i = 0; i < N; i++)
			for(j = 0; j < 4; j++){
				v[i] *= 10;
				v[i] += m[j][i] - '0';
			}
		
		for(i = 1; i < N-1; i++)
			s[i-1] = (F * v[i] + L) % 257;
		s[N-2] = 0;
		
		puts(s);
	}
	return 0;
}
