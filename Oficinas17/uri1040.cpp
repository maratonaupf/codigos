#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	double N1, N2, N3, N4, media, exame;
	cin >> N1 >> N2 >> N3 >> N4;
	media = (N1*2.0 + N2*3.0 + N3*4.0 + N4*1.0)/(10.0);
	cout << fixed << setprecision(1);
	cout << media << endl;
	
	if(media >= 7.0){
		cout << "Aluno aprovado." << endl;
	}else if(media < 5.0){
		cout << "Aluno reprovado." << endl;
	}else{
		cout << "Aluno em exame." << endl;
		cin >> exame;
		cout << "Nota do exame: " << exame << endl;
		media = (media + exame) / 2.0;
		if(media >= 5.0){
			cout << "Aluno aprovado." << endl;
		}else{
			cout << "Aluno reprovado." << endl;
		}
		cout << "Media final: " << media << endl;
	}
	return 0;
}
/// maratonaupf+subscribe@googlegroups.com
