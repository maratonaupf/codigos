/*
 * Leonardo Deliyannis Constantin
 * futebol
 */

#include <stdio.h>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
#define LEN 62
/*
#define DEBP
#ifdef DEBP
#define GRITA(_x) fprintf(stderr, "%s\n", _x);
#else
#define GRITA(_x) ;
#endif
*/

typedef vector<int> vi;
typedef vector<string> vs;
typedef map<string, int> msi;
msi m;

bool cmp(const string &a, const string &b){
	if(m[a] != m[b]) return m[a] > m[b];
	return a < b;
}

int main(){
	int N, ano, i, pts, tam;
	char s[LEN];
	string nome;
	msi::iterator it;
	while(scanf(" %d", &N) != EOF){
		m.clear();
		vi anos;
		vs v;
		while(N--){
			scanf(" %d", &ano);
			anos.push_back(ano);
			for(i = 0; i < 20; i++){
				nome = "";
				while(scanf(" %s", s), s[0] != '-'){
					if(!nome.empty())
						nome.push_back(' ');
					nome.append(s);
				}
				scanf(" %d", &pts);
				m[nome] += pts;
			}
		}
		for(it = m.begin(); it != m.end(); ++it){
			v.push_back(it->first);
		}
		sort(v.begin(), v.end(), cmp);
		printf("Os 10 melhores do ano de ");
		tam = (int)anos.size();
		for(i = 0; i < tam; i++){
			printf("%d", anos[i]);
			if(i < tam - 2) printf(", ");
			if(i == tam - 2) printf(" e ");
		} printf(":\n");
		for(i = 0; i < 10; i++){
			printf("%d - %s - %d\n", i+1, v[i].c_str(), m[v[i]]);
		}
	}
	return 0;
}
