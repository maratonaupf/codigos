#include <cstdio>
#include <cstring> 
#define MAX 303

int priori[256];

int main(){
	priori['(']=1; priori['+']=priori['-']=2; priori['*']=priori['/']=3;
	priori['^']=4;
	int T, i, topo, tam;
	char c, p[MAX], s[MAX];
	scanf("%d", &T);
	getchar();
	while(T--){
		topo=0;
		scanf("%s", s);
		for(i=0; s[i]; i++){
			if(s[i]=='(') p[topo++] = s[i];
			else if(s[i]==')'){
				do{
					c = p[--topo];
					if(c!='(') putchar(c);
				}while(c!='(');
			}
			else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='^'){
				while(topo && (priori[p[topo-1]] >= priori[s[i]])){
					putchar(p[--topo]);
				}
				p[topo++] = s[i];
			}
			else putchar(s[i]);
		}
		while(topo){
			putchar(p[--topo]);
		}
		putchar('\n');
	}
	return 0;
}
