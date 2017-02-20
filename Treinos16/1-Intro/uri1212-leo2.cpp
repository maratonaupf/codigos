//#include<stdio.h>
#include<iostream>
//#define DEBP // DEBug Prints

using namespace std;

int operations(int a, int b){
	int count = 0;
	int ra, rb;
	bool carry = false;
	//ra = a%10;
	//rb = b%10;
	while(a != 0 || b != 0){
		ra = a%10;
		rb = b%10;
		if(carry){
			(ra < rb) ? ra++ : rb++;
			carry = false;
		}
		if(ra + rb >= 10){
			count++;
			carry = true;
		}
		//a /= 10;
		a = a/10;
		//b /= 10;
		b = b/10;
	}
	return count;
}

int main(void){
	int a, b;
	int result;
	//while(scanf("%d %d", &a, &b), a || b){
	while(cin >> a >> b, a != 0 || b != 0){
#ifdef DEBP
		cout << "SOMA = " << a+b << endl;
#endif
		result = operations(a, b);
		if(result > 1){
			//printf("%d carry operations.\n", result);
			cout << result << " carry operations." << endl;
		}
		else{
			//printf("%s carry operation.\n", result != 0 ? "1" : "No");
			cout << (result == 0 ? "No" : "1") << " carry operation." << endl;
		}
	}
	return 0;
}
