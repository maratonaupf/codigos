#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#define MAX 51

using namespace std;

bool cmp(string a, string b){
	return a.size() > b.size();
}

int main(void){
	int N, tam;
	vector<string> v;
	v.reserve(MAX);
	char s[MAX];
	scanf("%d", &N);
	while(N--){
		tam = 0;
		while(true){
			scanf("%s", s);
			v.push_back((string)s);
			tam++;
			if(getchar() == '\n'){
				break;
			}
		}
		stable_sort(v.begin(), v.end(), cmp);
		for(int i = 0; i < tam; i++){
			printf("%s%c", v[i].c_str(), i < tam-1? ' ' : '\n');
		}
		v.clear();
	}
	return 0;
}
