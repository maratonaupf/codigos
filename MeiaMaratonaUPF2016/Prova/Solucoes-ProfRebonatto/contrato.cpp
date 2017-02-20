#include <iostream>
#include <string>

using namespace std;

int main(){
    int pos;
    char d;
    string valor;
    
    while(1){
        cin >> d;
        cin.ignore();
        cin >> valor;
        if ( (d == '0') && (valor[0] == '0') )
            break;
        
        while(1){
            pos = valor.find(d);
            
            if (pos == -1) //nao achou
                break;
            valor.erase(pos, 1);
        }
        
        for(int i=0; i < valor.length(); i++)
            if (valor[i] == '0'){
                valor.erase(i, 1);
                i--;
            }
            else
                break;
        if (valor.empty())
            cout << "0";
        else
            cout << valor;
        cout << endl;       
    }    
    return 0;
}
