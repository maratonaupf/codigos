#include<stdio.h>
#include<math.h>

/** AND BIT-A-BIT
 * i = 4;
 * x = 5;
 * i 0100
 * x 0101
 * & 0100
**/
void printbin(int x){
	for(int i = pow(2, floor(log(x)/log(2))); i > 0; i/=2){
		//i>>=1){
		// NÃO CONFUNDIR & e &&
		// & == 'E' bit-a-bit
		// && == 'E' lógico
		//putchar(i&x ? '1' : '0');
		if((i&x) != 0)
			putchar('1');
		else{
			putchar('0');
		}
	}
	printf(" bin\n");
}

int main(void){
	char num[40], base[4];
	int N, x;
	while(scanf("%d", &N) != EOF){
		for(int T = 1; T <= N; T++){
			scanf("%s %s", num, base);
			printf("Case %d:\n", T);
			
			if(base[0] == 'b'){
				x = 0;
				for(int i = 0; num[i] != '\0'; i++){
					//x <<= 1;
					x *= 2;
					//x += (num[i] == '1');
					if(num[i] == '1') x++;
				}
				printf("%d dec\n", x);
				printf("%x hex\n", x);
			}
			
			else if(base[0] == 'd'){
				sscanf(num, "%d", &x);
				printf("%x hex\n", x);
				printbin(x);
			}
			
			else if(base[0] == 'h'){
				sscanf(num, "%x", &x);
				printf("%d dec\n", x);
				printbin(x);
			}
			printf("\n");
		}
	}
	return 0;
}
