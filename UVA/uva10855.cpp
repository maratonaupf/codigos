#include<iostream>
#include<vector>
#include<string>
using namespace std;
//#define DEBP

vector<string> grid, sq;
vector<int> oc;
int N, n;

void readGrid(vector<string> &vet, int dim){
	//vet.reserve(N);
	vet.clear();
	string s;
	for(int i = 0; i < dim; i++){
		getline(cin, s);
		vet.push_back(s);
		#ifdef DEBP
		//cout << vet[i] << endl;
		#endif
	}
}

void verify(){
	int i, j, i2, j2;
	for(i2 = 0; i2 <= N-n; i2++){
		for(j2 = 0; j2 <= N-n; j2++){
			vector<bool> isValid(4, true);
			for(i = 0; i < n; i++){
				for(j = 0; j < n; j++){
					if(grid[i2+i][j2+j] != sq[i][j])
						isValid[0] = false;
					if(grid[i2+i][j2+j] != sq[(n-1)-j][i])
						isValid[1] = false;
					if(grid[i2+i][j2+j] != sq[(n-1)-i][(n-1)-j])
						isValid[2] = false;
					if(grid[i2+i][j2+j] != sq[j][(n-1)-i])
						isValid[3] = false;
				}
			}
			for(i = 0; i < 4; i++){
				if(isValid[i]) oc[i]++;
			}
		}
	}
}

int main(void){
	while(cin >> N >> n, N != 0){
		cin.ignore();
		readGrid(grid, N);
		readGrid(sq, n);
		oc.assign(4, 0);
		verify();
		for(int i = 0; i < 4; i++){
			cout << oc[i] << (i < 3 ? ' ' : '\n');
		}
		grid.clear();
		sq.clear();
	}
	return 0;
}
