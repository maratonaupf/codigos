#include<stdio.h>
#define MAX 112345
//#define DEBP
#ifdef DEBP
void printArray(int v[], int N){
	for(int i = 1; i <= N; i++)
		printf("%d%c", v[i], i < N ? ' ' : '\n');
}
#endif

int bit[MAX];

void update(int i, int val){
    while (i < MAX){
        bit[i] += val;
        i += (i & -i);
    }
}

int read(int i){
    int ret = 0;
    while (i > 0){
        ret += bit[i];
        i -= (i & -i);
    }
    return ret;
}

int main(void){
	int N, pos, v[MAX];
	char q;
	scanf("%d", &N);
	for(int i = 1; i <= N; i++){
		scanf("%d", v+i);
		update(i, v[i]);
	}
	while(scanf(" %c %d", &q, &pos) != EOF){
		if(q == 'a'){
			update(pos, -v[pos]);
#ifdef DEBP
			printArray(v, N);
			printArray(bit, N);
#endif
		}
		else if(q == '?'){
			printf("%d\n", read(pos-1));
		}
	}
	return 0;
}
