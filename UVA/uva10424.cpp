#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<algorithm>
#define MAX 28
#define EPS 1e-9
using namespace std;

int onify(int n){
	int ret = 0;
	while(n > 0){
		ret += n % 10;
		n /= 10;
	}
	return ret;
}

double ratio(char *s){
	int ans = 0;
	for(int i = 0; s[i]; i++)
		if(isalpha(s[i]))
			ans += toupper(s[i]) - '@';
	while(ans >= 10) ans = onify(ans);
	return (double) ans;
}

int main(void){
	char a[MAX], b[MAX];
	double ra, rb;
	while(fgets(a, MAX, stdin) != NULL){
		fgets(b, MAX, stdin);
		a[strlen(a)-1] = 0;
		b[strlen(b)-1] = 0;
		ra = ratio(a);
		rb = ratio(b);
		printf("%.2lf %%\n", min(ra, rb) * 100.0 / max(ra, rb));
	}
	return 0;
}
