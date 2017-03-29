#include<stdio.h>
#include<string.h>
#define MAX 112345

struct BIT{
	int bit[MAX];
	int size;
	void start(int N){
		memset(bit, 0, sizeof(bit));
		this->size = N;
	}
	void update(int i, int val){
		while(i <= this->size){
			bit[i] += val;
			i += i&-i;
		}
	}
	int read(int i){
		int ret = 0;
		while(i > 0){
			ret += bit[i];
			i -= i&-i;
		}
		return ret;
	}
};

int main(void){
	int N, aux;
	int i, resp;
	BIT b;
	while(scanf("%d", &N) != EOF){
		resp = 0;
		b.start(N);
		for(i = 0; i < N; i++){
			scanf("%d", &aux);
			resp += i - b.read(aux);
			b.update(aux, 1);
		}
		
		printf("%d\n", resp);
	}
	return 0;
}
