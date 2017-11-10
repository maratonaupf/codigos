#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

string cifra(string mensagem, string chave){
    string cifrada;
    char c, k;
    int i = 0, tamanho = (int)chave.size();
    while(chave.size() < mensagem.size()){
        chave.push_back(chave[i]);
        i++; 
        if(i == tamanho){
            i = 0;
        }
    }
    for(int i = 0; i < (int)mensagem.size(); i++){
        if(isalpha(mensagem[i])){
            c = toupper(mensagem[i]);
            if(isalpha(chave[i])){
                k = toupper(chave[i]);
            } else {
                k = chave[i];
            }
            cifrada.push_back('A' + ((c-'A' + k-'A') % 26));
            if(islower(mensagem[i])){
                cifrada[i] = tolower(cifrada[i]);
            }
        }
        else{
            cifrada.push_back(mensagem[i]);
        }
    }
    return cifrada;
}

string decifra(string cifrada, string chave){
    string mensagem;
    char c, k;
    int i = 0, tamanho = (int)chave.size();
    while(chave.size() < cifrada.size()){
        chave.push_back(chave[i]);
        i++; 
        if(i == tamanho){
            i = 0;
        }
    }
    for(int i = 0; i < (int)cifrada.size(); i++){
        if(isalpha(cifrada[i])){
            c = toupper(cifrada[i]);
            if(isalpha(chave[i])){
                k = toupper(chave[i]);
            } else {
                k = chave[i];
            }
            mensagem.push_back('A' + (((c-'A') + 26 - (k-'A')) % 26));
            if(islower(cifrada[i])){
                mensagem[i] = tolower(mensagem[i]);
            }
        }
        else{
            mensagem.push_back(cifrada[i]);
        }
    }
    return mensagem;
}

int main(){
    int opcao;
    string mensagem, chave;
    do{
        cout << "MENU" << endl;
        cout << "1 - cifrar uma mensagem" << endl;
        cout << "2 - decifrar uma mensagem" << endl;
        cout << "0 - sair do programa" << endl;
        cout << "Sua opcao: ";
        cin >> opcao;
        cin.ignore();
        switch(opcao){
            case 1: 
                cout << "Digite a mensagem a ser cifrada: ";
                getline(cin, mensagem);
                cout << "Digite a chave para cifrar a mensagem: ";
                getline(cin, chave);
                cout << "Mensagem cifrada: ";
                cout << cifra(mensagem, chave) << endl << endl;
                break;
            case 2:
                cout << "Digite a mensagem a ser decifrada: ";
                getline(cin, mensagem);
                cout << "Digite a chave para decifrar a mensagem: ";
                getline(cin, chave);
                cout << "Mensagem decifrada: ";
                cout << decifra(mensagem, chave) << endl << endl;
                break;
            case 0: break;
            default:
                cout << "Opcao invalida!" << endl;
                break;
        }
    }while(opcao != 0);
    return 0;
}
