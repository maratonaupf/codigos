#include<cstdio>
#include<cstring>

int fat[6] = {0, 1, 2, 6, 24, 120};

int main(void){	
	char s[8];
	int tam, t2, num, i;
	while(scanf("%s", s), strcmp(s, "0")){
		tam = t2 = strlen(s);
		num = 0;
		for(i=0; i<tam; i++){
			num+= fat[t2--] * (int)(s[i]-'0'); 
		}
		printf("%d\n", num);
	}
	return 0;
}
