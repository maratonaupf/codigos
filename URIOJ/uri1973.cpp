#include<stdio.h>
#include<string.h>
//#define DEBP // DEBug Prints
#define MAX 1000006

typedef long long ll;

int main(void){
	ll intactos, intactos2;
	int N, i, v[MAX], sitios;
	bool sentido, vis[MAX];
	
	while(scanf("%d", &N) != EOF){
		intactos = 0;
		memset(vis, 0, sizeof(vis));
		for(i = 0; i < N; i++){
			scanf("%d", v+i);
			intactos += (ll)v[i];
		};
		
		for(i = 0; 0 <= i && i < N; sentido ? i++ : i--){
			sentido = v[i] % 2;
			vis[i] = true;
			if(v[i]){
				v[i]--; intactos--;
			}
		}
		
		intactos2 = sitios = 0;
		for(i = 0; i < N; i++){
			intactos2 += (ll)v[i];
			if(vis[i]) sitios++;
		}
#ifdef DEBP
		if(intactos != intactos2){
			fprintf(stderr, "%d NÃO É %d.\n", intactos, intactos2);
			return 1;
		}
#endif // DEBP
		printf("%d %lld\n", sitios, intactos);
	}	
	return 0;
}
