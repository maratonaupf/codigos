#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main(void){
	int N;
	char aux[12];
	string s;
	vector<string> v;
	while(scanf("%d\n", &N) != EOF){
		while(N--){
			scanf("%s", aux);
			s = (string) aux;
			sort(s.begin(), s.end());
			v.push_back(s);
			while(next_permutation(s.begin(), s.end())){
				v.push_back(s);
			}
			for(vector<string>::iterator it = v.begin(); it != v.end(); ++it){
				printf("%s\n", it->c_str());
			}
			printf("\n");
			v.clear();
		}
	}
	return 0;
}
