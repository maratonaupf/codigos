#include<stdio.h>
#include<vector>
#include<algorithm> // min(), max()
using namespace std;
#define INFTO 112345678 // "infinite"
#define MAX 112345

int M;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main(void){
	char s[MAX];
	int i, j, ans, temp;
	vii ones, threes;
	int tam1, tam3;
	while(scanf("%d\n", &M) != EOF){
		for(i = 0; i < M; i++){
			fgets(s, MAX, stdin);
			for(j = 0; j < M; j++){
				if(s[j] == '1') ones.push_back(ii(i, j));
				if(s[j] == '3') threes.push_back(ii(i, j));
			}
		}
		ans = 0;
		tam1 = ones.size();   // cost of vector::size is O(n)
		tam3 = threes.size(); // cost of vector::size is O(n)
		for(i = 0; i < tam1; i++){
			temp = INFTO;
			for(j = 0; j < tam3; j++){
				temp = min(temp, abs(ones[i].first - threes[j].first) + 
					abs(ones[i].second - threes[j].second));
			}
			ans = max(ans, temp);
		}
		printf("%d\n", ans);
		ones.clear();
		threes.clear();
	}
	return 0;
}
