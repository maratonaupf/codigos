#include<stdio.h>
#include<math.h>

void printbin(int x){
	for(int i = pow(2, floor(log(x)/log(2))); i > 0; i>>=1){
		//printf(" %d", i);
		putchar(i&x ? '1' : '0');
	}
	printf(" bin\n");
}

int main(void){
	char s[40], base[4];
	int N, x, T;
	while(scanf("%d", &N) != EOF){
		for(T = 1; T <= N; T++){
			scanf("%s %s", s, base);
			printf("Case %d:\n", T);
			if(base[0] == 'b'){
				x = 0;
				for(int i = 0; s[i]; i++){
					x <<= 1;
					x += (s[i] == '1');
				}
				printf("%d dec\n", x);
				printf("%x hex\n", x);
			}
			else if(base[0] == 'd'){
				sscanf(s, "%d", &x);
				printf("%x hex\n", x);
				printbin(x);
			}
			else if(base[0] == 'h'){
				sscanf(s, "%x", &x);
				printf("%d dec\n", x);
				printbin(x);
			}
			printf("\n");
		}
	}
	return 0;
}
