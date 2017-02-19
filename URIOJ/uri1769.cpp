#include<cstdio>
#include<cstring>

void strange(char* s){
	int i;
	for(i=3; i<6; i++) s[i]=s[i+1];
	for(i=6; i<9; i++) s[i]=s[i+2];
	for(i=9; i<11; i++) s[i]=s[i+3];
	for(i=11; i<16; i++) s[i]=0;
}

int main(void){
	char s[16];
	int i, valid, digit, ac1, ac2;
	while(fgets(s, 16, stdin)!=NULL){
		strange(s);
		ac1 = ac2 = valid = 0;
		for(i=0; i<9; i++){
			digit = (int)(s[i] - '0');
			ac1 += digit * (i+1);
		}
		
		ac1 %= 11; ac1 %= 10;
		digit = s[9] - '0';
		
		if(ac1 == digit){
			for(i=0; i<9; i++){
				digit = (int)(s[i] - '0');
				ac2 += digit * (9-i);
			}
			
			ac2 %= 11; ac2 %= 10;
			digit = s[10] - '0';
			
			if (ac2 == digit) 
				valid = true; 
		}
		printf("CPF %svalido\n", valid?"":"in");
	}
	return 0;
}
