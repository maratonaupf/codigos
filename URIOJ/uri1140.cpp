#include<cstdio>
#include<cstring>
#include<cctype>
#define MAX 1123
//#define DEBP

bool is_tautogram(char *s){
	char aux[32], c;
	bool first = 1;
	int pos=0;
	while(sscanf(s+pos, "%s", aux) == 1){
#ifdef DEBP
		puts(aux);
#endif
		pos += strlen(aux)+1;
		if(first){
			c = tolower(aux[0]);
			first = 0;
		}
		else{
			if(tolower(aux[0]) != c)
				return false;
		}
	}
	return true;
}

int main(void){	
	char s[MAX];
	while(fgets(s, MAX, stdin), s[0] != '*'){
		printf("%c\n", is_tautogram(s) ? 'Y' : 'N');
	}
	return 0;
}
