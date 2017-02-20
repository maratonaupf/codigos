#include<stdio.h>
#include<set>
#include<string>
#include<string.h>

using namespace std;
	 
struct classcomp {
  bool operator() (const string& a, const string& b) const
  {return strcasecmp(a.c_str(), b.c_str()) != 1;}
};

int main(void){
	set<string,classcomp> myset;
	char aux[50];
	while(scanf("%s", aux) != EOF){
		string s = aux;
		if(myset.count(s) == 0){
			myset.insert(s);
		}else{
			printf("Elemento ja existe\n");
		}
	}
	set<string>::iterator it;
	for(it = myset.begin(); it!= myset.end(); ++it){
		printf("%s\n", it->c_str());
	}
	return 0;
}
