#include <iostream>

using namespace std;

string now, aux;

void change(){

    if(aux == "No"){
        return;
    }else if(aux == "+y"){
        if(now == "+x")
            now = "+y";
        else if(now == "-x")
            now = "-y";
        else if(now == "+y")
            now = "-x";
        else if(now == "-y")
            now = "+x";
        else if(now == "+z")
            now = "+z";
        else if(now == "-z")
            now = "-z";
    }else if(aux == "-y"){
        if(now == "+x")
            now = "-y";
        else if(now == "-x")
            now = "+y";
        else if(now == "+y")
            now = "+x";
        else if(now == "-y")
            now = "-x";
        else if(now == "+z")
            now = "+z";
        else if(now == "-z")
            now = "-z";
    }else if(aux == "+z"){
        if(now == "+x")
            now = "+z";
        else if(now == "-x")
            now = "-z";
        else if(now == "+y")
            now = "+y";
        else if(now == "-y")
            now = "-y";
        else if(now == "+z")
            now = "-x";
        else if(now == "-z")
            now = "+x";
    }else if(aux == "-z"){
        if(now == "+x")
            now = "-z";
        else if(now == "-x")
            now = "+z";
        else if(now == "+y")
            now = "+y";
        else if(now == "-y")
            now = "-y";
        else if(now == "+z")
            now = "+x";
        else if(now == "-z")
            now = "-x";
    }

}

int main(){

    int l;

    cin >> l;

    while(l){
        now = "+x";

        while(--l){
            cin >> aux;

            change();
        }

        cout << now << endl;

        cin >> l;
    }

}
