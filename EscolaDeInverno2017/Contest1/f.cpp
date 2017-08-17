
#include<iostream>
#include<vector>
using namespace std;

struct sala{
	int q  =0;
	int s  = 0;
	vector<int> d;
};

int aux ;
int memsoma;
vector<sala> vet;

void functesta(sala s ){
	aux +=s.q; 
	if(s.s > 0){
	for(int i = 0 ; i < s.s ; i ++ )
		functesta(vet[s.d[i]]);
	}
	return;	
	
}


int main(){
	int contro;
	while(cin >> contro && contro != 0  ){
		aux = 0;
		memsoma = 0;
		vet.clear();
		sala le;
		for(int i = 0 ; i< contro;i++){
      		cin >>le.q;
      		cin >>le.s;
      		if(le.s > 0){
				int z;
				for(int k = 0 ; k < le.s; k++){
					cin >> z;
					le.d.push_back(z);
				}
			}else{
					le.d.clear();
			}
			
			vet.push_back(le);
		}
		for(sala s : vet){
			aux = 0 ; 
			functesta(s);
			if(aux > memsoma)
				memsoma = aux;
		}
		cout << memsoma <<endl;
		
	
	}
	
	return 0;
}
