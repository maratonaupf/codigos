#include<cstdio>
#include<cctype>
#include<cstring>

bool claps(int n){
	int i;
	char s[32];
	
	if(n % 7 == 0) return true;
	sprintf(s, "%d", n);
	for(i=0; s[i]; i++)
		if(s[i] == '7') return true;
	return false;
}

int main(void){	
	int N, M, K, i, cont, n;
	bool rot; // 0 == pra direita, 1 == pra esquerda
	while(scanf("%d %d %d", &N, &M, &K), N){
		n = cont = 0;
		i=1; rot=0;
		while(cont < K){
			n++;
			if(i==M && claps(n))
				cont++;
			//rotação do laço
			if(i == N) rot = 1;
			if(i == 1) rot = 0;
			rot ? i-- : i++;
		}
		printf("%d\n", n);
	}
	return 0;
}
