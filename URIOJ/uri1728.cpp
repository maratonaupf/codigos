#include<cstdio>
#include<cstring>
#include<cctype>

void revstring(char *s){
	int i, stam=strlen(s)-1;
	char aux;
	for(i=0; i<=stam>>1; i++){
		//printf("Trocando %c por %c\n", s[i], s[stam-i]);
		aux = s[i];
		s[i] = s[stam-i];
		s[stam-i] = aux;
	}
}

int main(){
	int a, b, c;
	char s[32];
	while(scanf("\n%s", s)!=EOF){
		revstring(s);
		sscanf(s, "%d=%d+%d", &c, &a, &b);
		printf("%s\n", a+b==c? "True":"False");
	}
	return 0;
}
