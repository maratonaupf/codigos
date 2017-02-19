#include<cstdio>
#include<cstring>
 
void mkcpf(char* s, int ac1, int ac2){
	int i;
	s[11] = '-';
	s[12] = '0' + ac1;
	s[13] = '0' + ac2;
	
	for(i=10; i>7; i--)
		s[i] = s[i-2];
	
	for(i=6; i>3; i--)
		s[i] = s[i-1];
	
	s[3] = s[7] = '.';
	s[14] = s[15] = 0;
}
 
int main(void){
	char s[16];
	int i, digit, ac1, ac2;
	while(scanf("%s", s) != EOF){
		//strange(s);
		ac1 = ac2 = 0;
		for(i=0; i<9; i++){
			digit = (int)(s[i] - '0');
			ac1 += digit * (i+1);
		} 
		ac1 %= 11; ac1 %= 10;
		
		for(i=0; i<9; i++){
			digit = (int)(s[i] - '0');
			ac2 += digit * (9-i);
		}
		ac2 %= 11; ac2 %= 10;
		
		mkcpf(s, ac1, ac2);
		puts(s);
	}
	return 0;
}
