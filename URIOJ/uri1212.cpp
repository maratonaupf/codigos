#include<stdio.h>

int operations(int a, int b){
	int count = 0;
	int ra, rb;
	bool carry = 0;
	ra = a%10;
	rb = b%10;
	while(a || b){
		ra = a%10;
		rb = b%10;
		if(carry){
			(ra < rb) ? ra++ : rb++;
			carry = 0;
		}
		if(ra + rb >= 10){
			count++;
			carry = 1;
		}
		
		a /= 10;
		b /= 10;
	}
	return count;
}

int main(void){
	int a, b;
	int result;
	while(scanf("%d %d", &a, &b), a || b){
		result = operations(a, b);
		if(result > 1){
			printf("%d carry operations.\n", result);
		}
		else{
			printf("%s carry operation.\n", result ? "1" : "No");
		}
	}
	return 0;
}
