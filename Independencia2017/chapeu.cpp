/*
 * Leonardo Deliyannis Constantin
 * chapeu
 */

#include <stdio.h>
#include <string>
#include <set>
using namespace std;
#define LEN 212

typedef multiset<string> mss;

inline void printSet(const mss &myset){
	mss::iterator it;
	for(it = myset.begin(); it != myset.end(); ++it){
		printf("%s", it->c_str());
	} printf("\n");
}

int main(){
	int N;
	char s[LEN], h[LEN];
	while(scanf(" %d ", &N) != EOF){
		mss sly, gri, rav, huf;
		while(N--){
			fgets(s, LEN, stdin);
			fgets(h, LEN, stdin);
			switch(h[0]){
				case 'S': sly.insert(s); break;
				case 'H': huf.insert(s); break;
				case 'G': gri.insert(s); break;
				case 'R': rav.insert(s); break;
			}
		}
		printf("Slytherin:\n");
		printSet(sly);
		printf("Hufflepuff:\n");
		printSet(huf);
		printf("Gryffindor:\n");
		printSet(gri);
		printf("Ravenclaw:\n");
		printSet(rav);
	}
	return 0;
}
